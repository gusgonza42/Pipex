/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:18:34 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/18 14:43:42 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_args(char **paths, char *av)
{
	char	*tmp;
	char	*cmd;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		cmd = ft_strjoin(tmp, av);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		paths++;
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char **av, char **envp)
{
	dup2(pipex.pipe_fd[1], 1);
	close(pipex.pipe_fd[1]);
	close(pipex.pipe_fd[0]);
	dup2(pipex.infd, 0);
	close(pipex.infd);
	pipex.arg_cmd = ft_split(av[2], ' ');
	if (pipex.arg_cmd[0] && (access(pipex.arg_cmd[0], X_OK) == 0))
		pipex.cmd = pipex.arg_cmd[0];
	else
		pipex.cmd = check_args(pipex.paths, pipex.arg_cmd[0]);
	if (!pipex.cmd)
		exit(12);
	if (pipex.infd != 0)
		exit(1);
	execve(pipex.cmd, pipex.arg_cmd, envp);
}

void	second_child(t_pipex pipex, char **av, char **envp)
{
	dup2(pipex.pipe_fd[0], 0);
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	dup2(pipex.outfd, 1);
	close(pipex.outfd);
	if (pipex.outfd < 0)
		exit(1);
	pipex.arg_cmd = ft_split(av[3], ' ');
	if (pipex.arg_cmd[0] && (access(pipex.arg_cmd[0], X_OK) == 0))
		pipex.cmd = pipex.arg_cmd[0];
	else
		pipex.cmd = check_args(pipex.paths, pipex.arg_cmd[0]);
	if (!pipex.cmd)
		ft_errors(av[3], 1);
	execve(pipex.cmd, pipex.arg_cmd, envp);
}

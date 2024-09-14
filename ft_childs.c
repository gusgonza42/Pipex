/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:18:34 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/14 17:53:11 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	f_child_process(t_pipex pipex, char *cmd, char *cmds[], char *envp[])
{
	pipex.infd = open("yow", O_RDONLY);
	if (pipex.infd == -1)
		return (EXIT_FAILURE); // se puede usar exit aqui o la funcion o debe ser void?
	dup2(pipex.infd, STDIN_FILENO);
	dup2(pipex.pipe_fd[1], STDOUT_FILENO);
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	close(pipex.infd);
	execve(cmd, cmds, envp);
}

void	s_child_process(t_pipex pipex, char *cmd2, char *cmds2[], char *envp[])
{
	pipex.outfd = open("res", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	dup2(pipex.pipe_fd[0], STDIN_FILENO);
	dup2(pipex.outfd, STDOUT_FILENO);
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	close(pipex.infd);
	close(pipex.outfd);
	execve(cmd2, cmds2, envp);
}

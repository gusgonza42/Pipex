/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:18:34 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/17 14:37:31 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	f_child_process(t_pipex pipex, char **av, char *cmd, char *cmds[], char *envp[])
{
	pipex.infd = open(av[1], O_RDONLY);
	if (pipex.infd == -1)
		exit (EXIT_FAILURE); // se puede usar exit aqui o la funcion o debe ser void?
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

void	f_child_process(t_pipex pipex, char **av, char *envp[])
{
	pipex.infd = open(av[1], O_RDONLY);
	if (pipex.infd == -1)
		exit (EXIT_FAILURE);
	dup2(pipex.infd, STDIN_FILENO);
	dup2(pipex.pipe_fd[1], STDOUT_FILENO);
	close(pipex.pipe_fd[0]);
	close(pipex.pipe_fd[1]);
	close(pipex.infd);
	//a ver si funciona esto es usar . o -> se pueden mezclar? 
	pipex.arg_cmd = ft_split(av[2], ' ');
	pipex.path = get_path(pipex.arg_cmd, envp);

	execve(cmd, cmds, envp);
}

void	s_child_process(t_pipex pipex, char *av[], char *envp[])
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

//funcion test para bucar el path

char	*get_path(char *cmd, char **envp)
{
	//cositas test
}

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
/*
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
*/
void	f_child_process(t_pipex *pipex, char **av, char *envp[])
{
	pipex->infd = open(av[1], O_RDONLY);
	if (pipex->infd == -1)
		exit (EXIT_FAILURE);
	dup2(pipex->infd, STDIN_FILENO);
	dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	close(pipex->infd);
	//a ver si funciona esto es usar . o -> se pueden mezclar? 
	pipex->arg_cmd = ft_split(av[2], ' ');
	pipex->envpath = get_path(envp);
	pipex->paths = split_paths(pipex);
	if (pipex->paths == NULL)
		exit (mssg("Error paths \n"));
	check_cmd(pipex->paths, pipex->arg_cmd);

	//
	if (pipex->arg_cmd[0])
	execve(, envp);
}

void	s_child_process(t_pipex *pipex, char *av[], char *envp[])
{
	pipex->outfd = open("res", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	dup2(pipex->outfd, STDOUT_FILENO);
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	close(pipex->infd);
	close(pipex->outfd);
	//execve(cmd2, cmds2, envp);
}

//funcion test para bucar el path

char	*get_path(char **envp)
{
	while (*envp){
		if (ft_strincmp(*envp, "PATH=", 5))
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

void	split_paths(t_pipex pipex)
{
	if (pipex->envpath)
		pipex->paths = ft_split(pipex->envpath, ':');
	else
		pipex->paths = ft_split("", ':');
}

//usar el access para comprobar si el comando existe y se ejecuta 
//en caso de que no me apsen la ruta completa
char	check_cmd(char **paths, char *arg_cmd)
{
	char	*tmp;
	char	*cmd;
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		cmd = ft_strjoin_free(tmp, arg_cmd);
		if (access(cmd, X_OK) == 0)
		paths++;
	}
}

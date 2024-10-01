/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:36:37 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/18 13:27:48 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include "libft.h"
# include "ft_printf.h"



// Struct proyect+
typedef struct s_pipex
{
	int		infd;
	int		outfd;
	int		p_id;
	int		p_id_2;
	int		pipe_fd[2];
	char	*cmd;
	char	**arg_cmd;
	char	*envpath;
	char	**paths;
	int		bol;
}   t_pipex;

// child//s
//void	f_child_process(t_pipex pipex, char **av, char *cmd, char *cmds[], char *envp[]);
//void	s_child_process(t_pipex pipex, char *cmd2, char *cmds2[], char *envp[]);

//void	f_child_process(t_pipex pipex, char **av, char *envp[]);
//void	s_child_process(t_pipex pipex, char **av, char *envp[]);
void	second_child(t_pipex pipex, char **argv, char **env);
void	first_child(t_pipex pipex, char **argv, char **env);

void ft_errors(char *str, int error);
char **ft_get_path(char **e, t_pipex pipex);

char *check_cmd(char **paths, char **argv);
#endif


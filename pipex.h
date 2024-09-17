/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:36:37 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/17 14:22:46 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
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
	char	**arg_cmd;
	char	*path;
}   t_pipex;

// childs
void	f_child_process(t_pipex pipex, char **av, char *cmd, char *cmds[], char *envp[]);
void	s_child_process(t_pipex pipex, char *cmd2, char *cmds2[], char *envp[]);

// error
int	mssg(char *fail);

#endif


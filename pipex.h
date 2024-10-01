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

# include "ft_printf.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <unistd.h>

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
}			t_pipex;

void		second_child(t_pipex pipex, char **argv, char **env);
void		first_child(t_pipex pipex, char **argv, char **env);

void		ft_errors(char *str, int error);
char		**ft_get_path(char **e, t_pipex pipex);

char		*check_cmd(char **paths, char **argv);

#endif
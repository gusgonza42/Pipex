/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:36:37 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/13 15:47:58 by gusgonza         ###   ########.fr       */
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
	int infd;
    int outfd;
    int p_id;
    int p_id_2;
    int pipe_fd[2];
}   t_pipex;


#endif


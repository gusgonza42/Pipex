/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:05:28 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/17 14:08:32 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	mssg(char *fail)
{
	ft_printf("%s\n", fail);
	return(1);
}

void	check_args(int ac)
{
	if (ac > 5)
		mss("Too few arguments\n");
	if (ac < 5)
		mss("Too many arguments\n");
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:05:28 by gusgonza          #+#    #+#             */
/*   Updated: 2024/09/18 11:22:32 by gusgonza         ###   ########.fr       */
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
		mssg("Too few arguments\n");
	if (ac < 5)
		mssg("Too many arguments\n");
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:35:24 by gusgonza          #+#    #+#             */
/*   Updated: 2024/03/11 19:35:27 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_puthexa(unsigned long nb, char *base, int isptr)
{
	int	length;
	int	check;

	length = 0;
	if (isptr)
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		length += 2;
	}
	if (nb > 15)
	{
		check = ft_puthexa(nb / 16, base, 0);
		if (check == -1 || ft_putchar(base[(nb % 16)]) == -1)
			return (-1);
		length += check + 1;
	}
	else
	{
		if (ft_putchar(base[nb]) == -1)
			return (-1);
		length++;
	}
	return (length);
}

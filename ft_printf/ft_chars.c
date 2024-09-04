/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:34:44 by gusgonza          #+#    #+#             */
/*   Updated: 2024/03/11 19:34:45 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	pos;

	pos = 0;
	if (!str)
		str = "(null)";
	while (str[pos])
	{
		if (write(1, &str[pos], 1) == -1)
			return (-1);
		pos++;
	}
	return (pos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:35:00 by gusgonza          #+#    #+#             */
/*   Updated: 2024/03/11 19:37:07 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_putnbr(long number)
{
	int	length;
	int	recursive_length;

	length = 0;
	if (number < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		length++;
		number = -number;
	}
	if (number > 9)
	{
		recursive_length = ft_putnbr(number / 10);
		if (recursive_length == -1 || ft_putchar((number % 10) + 48) == -1)
			return (-1);
		length += recursive_length + 1;
	}
	else
	{
		if (ft_putchar(number + 48) == -1)
			return (-1);
		length++;
	}
	return (length);
}

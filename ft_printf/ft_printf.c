/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusgonza <gusgonza@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:29:04 by gusgonza          #+#    #+#             */
/*   Updated: 2024/03/11 19:29:06 by gusgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_check(const char format, va_list args)
{
	int	length;

	length = 0;
	if (format == 'c')
		length = ft_putchar(va_arg(args, int));
	else if (format == 's')
		length = ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		length = ft_puthexa(va_arg(args, unsigned long), LHEX_BASE, 1);
	else if (format == 'd' || format == 'i')
		length = ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		length = ft_putnbr(va_arg(args, unsigned int));
	else if (format == 'x')
		length = ft_puthexa(va_arg(args, unsigned int), LHEX_BASE, 0);
	else if (format == 'X')
		length = ft_puthexa(va_arg(args, unsigned int), UHEX_BASE, 0);
	else if (format == '%')
		length = ft_putchar('%');
	if (length == -1)
		return (-1);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	int		char_pos;
	int		chars_written;
	int		total_chars;
	va_list	args;

	char_pos = 0;
	chars_written = 0;
	total_chars = 0;
	va_start(args, format);
	while (format[char_pos] && chars_written != -1)
	{
		if (format[char_pos] == '%')
			chars_written = ft_format_check(format[++char_pos], args);
		else
			chars_written = write(1, &format[char_pos], 1);
		total_chars += chars_written;
		char_pos++;
	}
	va_end(args);
	return (total_chars);
}

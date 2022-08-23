/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:28:14 by ayogun            #+#    #+#             */
/*   Updated: 2022/08/23 16:09:03 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list *args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length = ft_printchar(va_arg(*args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(*args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(*args, uintptr_t));
	else if (format == 'd' || format == 'i')
		print_length += ft_printnbr(va_arg(*args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(*args, unsigned int), format);
	else if (format == '%')
		print_length += ft_printpercent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(&args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}

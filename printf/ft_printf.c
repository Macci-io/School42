/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:25:30 by snicky            #+#    #+#             */
/*   Updated: 2021/11/27 14:27:19 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ap_conversion(const char *format, int *outsym, va_list ap)
{
	if (*format == 'c')
		ft_putchar(outsym, ap);
	else if (*format == 's')
		ft_putstr(outsym, ap);
	else if (*format == 'u')
		ft_put_uns(outsym, ap);
	else if (*format == 'x' || *format == 'X')
		ft_put_x(outsym, ap, *format);
	else if (*format == 'p')
		ft_put_p(outsym, ap);
	else if (*format == 'd' || *format == 'i')
		ft_put_di(outsym, ap);
	else if (*format == '%')
	{
		write(1, "%", 1);
		(*outsym)++;
	}
	else
	{
		write(1, format, 1);
		(*outsym)++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		outsym;

	va_start(ap, format);
	outsym = 0;
	while (*format)
	{
		if (*format == '%')
		{
			ap_conversion(++format, &outsym, ap);
			format++;
		}
		else
		{
			write(1, format++, 1);
			outsym++;
		}
	}
	va_end(ap);
	return (outsym);
}

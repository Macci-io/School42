/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:42:08 by snicky            #+#    #+#             */
/*   Updated: 2021/11/03 03:30:32 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_put_di(int *outsym, va_list ap)
{
	int	d;

	d = va_arg(ap, int);
	ft_putnbrdi_fd(d, 1);
	*outsym += f_len(d);
}

int	f_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_putnbrdi_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbrdi_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
		ft_putnbrdi_fd(n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbrdi_fd(n / 10, fd);
		n %= 10;
		ft_putchar_fd(n + 48, fd);
	}
	else if (n < 10)
		ft_putchar_fd(n + 48, fd);
}

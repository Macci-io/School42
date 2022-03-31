/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 08:21:50 by snicky            #+#    #+#             */
/*   Updated: 2021/11/03 03:28:20 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_put_uns(unsigned int *outsym, va_list ap)
{
	unsigned int	count;

	count = va_arg(ap, unsigned int);
	ft_put_uns_nbr_fd(count, 1, outsym);
}

void	ft_put_uns_nbr_fd(unsigned int n, int fd, int *outsym)
{
	if (n >= 10)
	{
		ft_put_uns_nbr_fd(n / 10, fd, outsym);
		n %= 10;
	}
	if (n < 10)
		ft_putchar_fd(n + 48, fd);
	(*outsym)++;
}

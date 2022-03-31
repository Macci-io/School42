/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 10:41:12 by snicky            #+#    #+#             */
/*   Updated: 2021/11/03 03:25:36 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_put_x(int *outsym, va_list ap, char a)
{
	unsigned int	count;

	count = va_arg(ap, unsigned int);
	ft_put_x2(count, outsym, a);
}

void	ft_put_x2(unsigned long long int n, int *outsym, char a)
{
	if (n >= 16)
	{
		ft_put_x2(n / 16, outsym, a);
		n %= 16;
	}
	if (n > 9 && n < 16)
	{
		if (a == 'x')
			ft_putchar_fd((n % 10) + 97, 1);
		else
			ft_putchar_fd((n % 10) + 65, 1);
	}
	else
		ft_putchar_fd(n + 48, 1);
	(*outsym)++;
}

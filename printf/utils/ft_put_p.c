/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:22:27 by snicky            #+#    #+#             */
/*   Updated: 2021/11/03 03:29:15 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_put_p(int *outsym, va_list ap)
{
	unsigned long long int	p;

	p = va_arg(ap, unsigned long long int);
	write(1, "0x", 2);
	*outsym += 2;
	ft_put_x2(p, outsym, 'x');
}

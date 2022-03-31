/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:35:46 by snicky            #+#    #+#             */
/*   Updated: 2021/11/03 03:20:45 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putchar(int *outsym, va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	(*outsym)++;
}
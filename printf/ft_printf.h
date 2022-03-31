/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 20:31:38 by snicky            #+#    #+#             */
/*   Updated: 2021/11/03 03:31:45 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		f_len(int n);
int		ft_printf(const char *format, ...);
void	ft_putnbrdi_fd(int n, int fd);
void	ap_conversion(const char *format, int *outsym, va_list ap);
void	ft_putchar(int *outsym, va_list ap);
void	ft_putstr(int *outsym, va_list ap);
void	ft_put_uns(unsigned int *outsym, va_list ap);
void	ft_put_uns_nbr_fd(unsigned int n, int fd, int *outsym);
void	ft_putchar_fd(char c, int fd);
void	ft_put_p(int *outsym, va_list ap);
void	ft_put_x2(unsigned long long int n, int *outsym, char a);
void	ft_put_x(int *outsym, va_list ap, char a);
void	ft_put_di(int *outsym, va_list ap);

#endif

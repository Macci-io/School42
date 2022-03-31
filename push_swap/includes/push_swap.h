/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:40:31 by snicky            #+#    #+#             */
/*   Updated: 2022/01/21 23:40:37 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define FALSE 0
# define TRUE 1

typedef struct s_stack
{
	int	size;
	int	*array;
	int	*index;
	int	largest_number;
}				t_stack;

void	first_move(t_stack *stack_a, t_stack *stack_b);
void	second_move(t_stack *stack_a, t_stack *stack_b);

char	**check_input_validity(int argc, char **argv);
int		check_repeated(t_stack *stack_a);
int		check_array_sorted(t_stack *stack_a);
int		check_if_sorted(t_stack *stack_a);
void	sort_index(t_stack *stack_a);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
int		choose_head(t_stack *stack_a);

void	s(t_stack *stack, char c);
void	r(t_stack *stack, char c);
void	p(t_stack *stack_a, t_stack *stack_b, char c);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rr_(t_stack *stack, char c);
void	rrr(t_stack *stack_a, t_stack *stack_b);

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);

void	extend_stack(t_stack *stack);
void	reduce_stack(t_stack *stack);

int		ft_isdigits(char *c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *string1, const char *string2, size_t size);
double	ft_atod(const char *nptr);
int		ft_isdigit(int c);
int		ft_strncmp(const char *string1, const char *string2, size_t size);
char	*ft_strdup(const char *str);
void	ft_bzero(void *str, size_t size);

void	error_message(int error);

#endif
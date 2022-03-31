/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:04:33 by awarren           #+#    #+#             */
/*   Updated: 2022/01/21 23:41:27 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	bit_comparison(int binary_number, int bits_to_shift)
{
	return ((binary_number >> bits_to_shift) & 1);
}

static int	most_significant_bit(int largest_number)
{
	int	bits;

	bits = 31;
	while (bit_comparison(largest_number, bits) != 1 && bits >= 0)
		bits--;
	return (bits);
}

static void	push_zeros_to_stack_b(t_stack *stack_a,
	t_stack *stack_b, int bits_to_shift)
{
	int	i;
	int	stop;

	i = 0;
	stop = stack_a->size;
	while (i < stop)
	{
		if (bit_comparison(stack_a->index[0], bits_to_shift) == 0)
			p(stack_a, stack_b, 'b');
		else
			r(stack_a, 'a');
		i++;
	}
}

static void	push_zeros_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size > 0)
		p(stack_b, stack_a, 'a');
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	bits_to_shift;
	int	cycles;

	bits_to_shift = 0;
	cycles = most_significant_bit(stack_a->size);
	while (bits_to_shift <= cycles)
	{
		push_zeros_to_stack_b(stack_a, stack_b, bits_to_shift);
		push_zeros_to_stack_a(stack_a, stack_b);
		bits_to_shift++;
		if (check_if_sorted(stack_a))
			break ;
	}
}

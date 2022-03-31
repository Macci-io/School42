/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:04:27 by awarren           #+#    #+#             */
/*   Updated: 2022/01/21 23:51:10 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_sort(t_stack *stack_a)
{
	if (check_if_sorted(stack_a))
		return ;
	if (stack_a->index[0] < stack_a->index[1])
	{
		rr_(stack_a, 'a');
		if (stack_a->index[0] > stack_a->index[1])
			s(stack_a, 'a');
	}
	else
	{
		if (stack_a->index[0] < stack_a->index[2])
			s(stack_a, 'a');
		else
		{
			r(stack_a, 'a');
			if (stack_a->index[0] > stack_a->index[1])
				s(stack_a, 'a');
		}
	}
}

void	five_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	smallest_number;

	smallest_number = 1;
	while (stack_a->size > 3)
	{
		i = 0;
		while (stack_a->index[i] != smallest_number)
			i++;
		if (i != 0)
		{
			if (i > stack_a->size / 2)
				while (stack_a->index[0] != smallest_number)
					rr_(stack_a, 'a');
			else
				while (stack_a->index[0] != smallest_number)
					r(stack_a, 'a');
		}
		p(stack_a, stack_b, 'b');
		smallest_number++;
	}
	three_sort(stack_a);
	while (stack_b->size > 0)
		p(stack_b, stack_a, 'a');
}

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		s(stack_a, 'a');
	if (stack_a->size > 3 && stack_a->size < 6)
		five_sort(stack_a, stack_b);
	else
		three_sort(stack_a);
}

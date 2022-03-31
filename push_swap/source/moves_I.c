/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_I.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:36:00 by awarren           #+#    #+#             */
/*   Updated: 2022/01/21 23:41:08 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	s(t_stack *stack, char c)
{
	int	temp;

	temp = stack->index[0];
	stack->index[0] = stack->index[1];
	stack->index[1] = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	r(t_stack *stack, char c)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack->index[0];
	while (i < stack->size)
	{
		stack->index[i] = stack->index[i + 1];
		i++;
	}
	stack->index[i - 1] = temp;
	if (c == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	p(t_stack *stack_a, t_stack *stack_b, char c)
{
	extend_stack(stack_b);
	stack_b->index[0] = stack_a->index[0];
	reduce_stack(stack_a);
	stack_b->size++;
	stack_a->size--;
	if (c == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

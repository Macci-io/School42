/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_II.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:04:46 by awarren           #+#    #+#             */
/*   Updated: 2022/01/21 23:41:14 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int		temp;

	temp = stack_a->index[0];
	stack_a->index[0] = stack_a->index[1];
	stack_a->index[1] = temp;
	temp = stack_b->index[0];
	stack_b->index[0] = stack_b->index[1];
	stack_b->index[1] = temp;
	write(1, "ss\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	int		temp;
	int		i;

	i = 0;
	temp = stack_a->index[0];
	while (i < stack_a->size)
	{
		stack_a->index[i] = stack_a->index[i + 1];
		i++;
	}
	stack_a->index[i] = temp;
	i = 0;
	temp = stack_b->index[0];
	while (i < stack_b->size)
	{
		stack_b->index[i] = stack_b->index[i + 1];
		i++;
	}
	stack_b->index[i] = temp;
	write(1, "rr\n", 3);
}

void	rr_(t_stack *stack, char c)
{
	int		temp;
	int		i;

	i = stack->size;
	temp = stack->index[stack->size - 1];
	while (--i > 0)
		stack->index[i] = stack->index[i - 1];
	stack->index[i] = temp;
	if (c == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	int		temp;
	int		i;

	i = 0;
	temp = stack_a->index[stack_a->size];
	while (i < stack_a->size)
	{
		stack_a->index[i] = stack_a->index[i + 1];
		i++;
	}
	stack_a->index[i] = temp;
	i = 0;
	temp = stack_b->index[stack_b->size];
	while (i < stack_b->size)
	{
		stack_b->index[i] = stack_b->index[i + 1];
		i++;
	}
	stack_b->index[i] = temp;
	write(1, "rrr\n", 4);
}

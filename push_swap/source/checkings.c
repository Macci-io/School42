/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicky <snicky@student.42.ru>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:40:58 by snicky            #+#    #+#             */
/*   Updated: 2022/01/24 15:38:25 by snicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_repeated(t_stack *stack_a)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < stack_a->size)
	{
		temp = stack_a->array[i];
		j = i + 1;
		while (j < stack_a->size)
		{
			if (temp == stack_a->array[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	check_array_sorted(t_stack *stack_a)
{
	int	i;

	i = -1;
	while (++i < stack_a->size - 1)
	{
		if (stack_a->array[i] > stack_a->array[i + 1])
			return (FALSE);
	}
	return (TRUE);
}

int	check_if_sorted(t_stack *stack_a)
{
	int	i;

	i = -1;
	while (++i < stack_a->size - 1)
	{
		if (stack_a->index[i] > stack_a->index[i + 1])
			return (FALSE);
	}
	return (TRUE);
}

void	sort_index(t_stack *stack_a)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	while (i < stack_a->size)
	{
		j = 0;
		count = 0;
		while (j < stack_a->size)
		{
			if (stack_a->array[i] > stack_a->array[j])
				count++;
			j++;
		}
		stack_a->index[i] = count + 1;
		i++;
	}
}

char	**check_input_validity(int argc, char **argv)
{
	char	**args;
	int		i;

	if (argc == 2)
			args = ft_split (argv[1], ' ');
	else
	{
		args = malloc(sizeof(char *) * argc);
		i = 1;
		while (argv[i])
		{
			args[i - 1] = ft_strdup(argv[i]);
			i++;
		}
		args[i - 1] = NULL;
	}	
	return (args);
}

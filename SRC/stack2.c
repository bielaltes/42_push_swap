/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:53:35 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/16 17:39:38 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/push_swap.h"
#include "../libft/libft.h"

int	min_stack(t_stack *stack)
{
	t_node	*aux;
	int		min;

	min = 2147483647;
	aux = stack->top;
	while (aux != stack->bot)
	{
		if (aux->content < min)
			min = aux->content;
		aux = aux->ant;
	}
	if (aux->content < min)
			min = aux->content;
	return (min);
}

int	max_stack(t_stack *stack)
{
	t_node	*aux;
	int		max;

	max = -2147483648;
	aux = stack->top;
	while (aux != stack->bot)
	{
		if (aux->content > max)
			max = aux->content;
		aux = aux->ant;
	}
	if (aux->content > max)
			max = aux->content;
	return (max);
}

static void	max4_extra(t_node *aux, int *max)
{
	if (aux->content > max[0])
	{
		max[3] = max[2];
		max[2] = max[1];
		max[1] = max[0];
		max[0] = aux->content;
	}
	else if (aux->content > max[1])
	{
		max[3] = max[2];
		max[2] = max[1];
		max[1] = aux->content;
	}
	else if (aux->content > max[2])
	{
		max[3] = max[2];
		max[2] = aux->content;
	}
	else if (aux->content > max[3])
		max[3] = aux->content;
}

int	*max4_stack(t_stack *stack)
{
	t_node	*aux;
	int		*max;
	int		first;

	first = 1;
	max = malloc(sizeof(int) * 4);
	max[0] = -2147483648;
	aux = stack->top;
	while (aux != stack->top || first)
	{
		first = 0;
		max4_extra(aux, max);
		aux = aux->ant;
	}
	return (max);
}

int	sorted(t_stack *a, int n)
{
	int		i;
	t_node	*aux;

	if (a->size <= 1)
		return (1);
	i = 2;
	aux = a->top->ant;
	while (aux != a->top && i <= n)
	{
		if (aux->content < aux->next->content)
			return (0);
		aux = aux->ant;
		++i;
	}
	return (1);
}

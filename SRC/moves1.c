/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:03:42 by baltes-g          #+#    #+#             */
/*   Updated: 2023/01/28 18:58:27 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/push_swap.h"
#include "../libft/libft.h"

void	swap(t_stack *s)
{
	int aux;

	if (s->size >= 2)
	{
		aux = s->top->content;
		s->top->content = s->top->ant->content;
		s->top->ant->content = aux;
	}
}

void	sswap(t_stack *s1, t_stack *s2)
{
	swap(s1);
	swap(s2);
}

void	push(t_stack *s1, t_stack *s2)
{
	int aux;

	if (s2->size >= 1)
	{
		aux = s2->top->content;
		pop(s2);
		push_top(s1, aux);
	}
}

void	rotate(t_stack *s)
{
	if (s->size > 1)
	{
		s->top = s->top->ant;
		s->bot = s->bot->ant;
	}
}

void	rrotate(t_stack *s1, t_stack *s2)
{
	rotate(s1);
	rotate(s2);
}

void	revrotate(t_stack *s)
{
	if (s->size > 1)
	{
		s->top = s->top->next;
		s->bot = s->bot->next;
	}
}

void	revvrrotate(t_stack *s1, t_stack *s2)
{
	revrotate(s1);
	revrotate(s2);
}
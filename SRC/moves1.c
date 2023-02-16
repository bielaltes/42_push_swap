/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:03:42 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/16 16:46:46 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/push_swap.h"
#include "../libft/libft.h"

void	swap(t_stack *s)
{
	int	aux;

	if (s->size >= 2)
	{
		aux = s->top->content;
		s->top->content = s->top->ant->content;
		s->top->ant->content = aux;
	}
	ft_printf("s%c\n", s->name);
}

void	sswap(t_stack *s1, t_stack *s2)
{
	swap(s1);
	swap(s2);
}

void	push(t_stack *s1, t_stack *s2)
{
	int	aux;

	if (s2->size >= 1)
	{
		aux = s2->top->content;
		pop(s2);
		push_top(s1, aux);
	}
	ft_printf("p%c\n", s1->name);
}

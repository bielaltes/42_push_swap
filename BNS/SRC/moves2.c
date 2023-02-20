/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:46:01 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/20 17:05:10 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/checker.h"
#include "../../libft/libft.h"

void	rotate(t_stack *s)
{
	if (s->size > 1)
	{
		s->top = s->top->ant;
		s->bot = s->bot->ant;
	}
	ft_printf("r%c\n", s->name);
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
	ft_printf("rr%c\n", s->name);
}

void	revvrrotate(t_stack *s1, t_stack *s2)
{
	revrotate(s1);
	revrotate(s2);
}

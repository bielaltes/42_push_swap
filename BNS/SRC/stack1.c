/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:49:31 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/20 17:05:10 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/checker.h"
#include "../../libft/libft.h"

void	init_stack(t_stack *stack, char name)
{
	stack->top = NULL;
	stack->bot = NULL;
	stack->size = 0;
	stack->name = name;
}

void	push_top(t_stack *stack, int num)
{
	t_node	*aux;

	if (stack->size == 0)
	{
		aux = malloc(sizeof(t_node));
		stack->top = aux;
		stack->bot = aux;
		aux->content = num;
		aux->next = NULL;
		aux->ant = NULL;
	}
	else
	{
		aux = malloc(sizeof(t_node));
		stack->top->next = aux;
		aux->ant = stack->top;
		aux->next = stack->bot;
		stack->bot->ant = aux;
		stack->top = aux;
		aux->content = num;
	}
	stack->size += 1;
}

void	pop(t_stack *stack)
{
	t_node	*aux;

	if (stack->size != 0)
	{
		if (stack->size == 1)
		{
			free(stack->top);
			stack->top = NULL;
			stack->bot = NULL;
		}
		else
		{
			aux = stack->top->ant;
			free(stack->top);
			stack->top = aux;
			stack->top->next = stack->bot;
			stack->bot->ant = stack->top;
		}
		stack->size -= 1;
	}
}

void	print_stack(t_stack *stack)
{
	t_node	*aux;

	aux = stack->top;
	ft_printf("stack %c:", stack->name);
	while (aux != stack->bot && aux)
	{
		ft_printf("%d ", aux->content);
		aux = aux->ant;
	}
	if (aux)
		ft_printf("%d", aux->content);
	write(1, "\n", 1);
}

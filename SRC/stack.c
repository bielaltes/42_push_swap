/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:49:31 by baltes-g          #+#    #+#             */
/*   Updated: 2023/01/28 18:30:31 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/push_swap.h"
#include "../libft/libft.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->bot = NULL;
	stack->size = 0;
}

void	push_top(t_stack *stack, int num)
{
	t_node	*aux;

	if (stack->top == NULL)
	{
		stack->top = malloc(sizeof(t_node));
		stack->bot = stack->top;
		stack->top->content = num;
		stack->top->next = NULL;
		stack->top->ant = NULL;
	}
	else
	{
		aux = malloc(sizeof(t_node));
		stack->top->next = aux;
		aux->ant = stack->top;
		aux->next = stack->bot;
		stack->bot->ant = aux;
		stack->top = aux;
		stack->top->content = num;
	}
	stack->size +=1;
}

void	pop(t_stack *stack)
{
	t_node	*aux;

	if (stack->top != NULL)
	{
		aux = stack->top->ant;
		free(stack->top);
		stack->top = aux;
		stack->size -=1;
	}
}

void print_stack(t_stack *stack)
{
	t_node *aux;

	aux = stack->top;
	while (aux != stack->bot)
	{
		ft_printf("%d ", aux->content);
		aux = aux->ant;
	}
	ft_printf("%d\n", aux->content);
}
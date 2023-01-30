/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:49:31 by baltes-g          #+#    #+#             */
/*   Updated: 2023/01/30 10:58:49 by baltes-g         ###   ########.fr       */
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
	stack->size +=1;
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
		stack->size -=1;
	}
}

int	min_stack(t_stack *stack)
{
	t_node *aux;
	int	min;

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
	t_node *aux;
	int	max;

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

void print_stack(t_stack *stack)
{
	t_node *aux;

	aux = stack->top;
	while (aux != stack->bot && aux)
	{
		ft_printf("%d ", aux->content);
		aux = aux->ant;
	}
	if (aux)
		ft_printf("%d\n", aux->content);
}
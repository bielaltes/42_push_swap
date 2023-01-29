/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:07:36 by baltes-g          #+#    #+#             */
/*   Updated: 2023/01/29 13:29:36 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/push_swap.h"
#include "../libft/libft.h"

void	fill_array(int *numbers, t_stack *a)
{
	t_node	*aux;
	int		i;

	i = 0;
	aux = a->top;
	while (aux != a->bot)
	{
		numbers[i] = aux->content;
		aux = aux->ant;
		++i;
	}
	numbers[i] = aux->content;
}

void	sort_array(int *numbers, int n)
{
	int i;
	int j;
	int a;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (numbers[i] > numbers[j]) 
			{
				a =  numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = a;
			}
			j++;
		}
		++i;
	}
}

int	*compute_delimiters(t_stack *a, int chunk)
{
	int	*numbers;
	int	*delimiters;
	int	i;

	numbers = malloc(sizeof(int) * (a->size + 1));
	numbers[a->size] = -1;
	delimiters = malloc(sizeof(int)  * (a->size / chunk + 1));
	delimiters[a->size / chunk] = -1;
	fill_array(numbers, a);
	sort_array(numbers, a->size);
	i = 0;
	while (i < (a->size / chunk))
	{
		delimiters[i] = numbers[i * chunk];
		++i;
	}
	free(numbers);
	return (delimiters);
}

int	smart_rot(t_stack *a, int min, int max)
{
	int		sum;
	int		found;
	t_node	*aux;

	found = 0;
	aux = a->top;
	sum = 0;
	while (aux && aux != a->bot && !found)
	{
		if (aux->content > min && aux->content <= max)
			found = sum;
		aux = aux->ant;
		++sum;
	}
	if (!found)
		return (0);
	aux = a->bot;
	sum = 0;
	while (aux != a->top && sum < found)
	{
		if (aux->content > min && aux->content <= max)
			return (RRA);
		aux = aux->next;
		++sum;
	}
	return (RA);
}

void	send_b(t_stack *a, t_stack *b, int min, int max)
{
	int end;

	end = 1;
	while (end)
	{
		end = smart_rot(a, min, max);
		print_stack(a);
		print_stack(b);
		ft_printf("%d\n", end);
		if (end == RA)
		{
			while (a->top->content > max || a->top->content < min)
			{
				rotate(a);
				ft_printf("ra\n");
			}
			push(b, a);
			ft_printf("pb\n");
		}
		else if (end == RRA)
		{
			while (a->top->content > max || a->top->content < min)
			{
				revrotate(a);
				ft_printf("rra\n");
			}
			push(b, a);
			ft_printf("pb\n");
		}
		else if (end == 0 && (a->top->content > max || a->top->content < min))
		{
			push(b, a);
			ft_printf("pb\n");
		}
	}
}

void get_back(t_stack *a, t_stack *b)
{
	int rot;
	int	max;

	while (b->size != 0)
	{
		max = max_stack(b);
		//ft_printf("%d", max);
		rot = smart_rot(b, max-1, max);
		if (rot == RA)
		{
			while (a->top->content != max)
			{
				rotate(a);
				ft_printf("rb\n");
			}
			push(a, b);
			ft_printf("pa\n");
		}
		else if (rot == RRA)
		{
			while (a->top->content != max)
			{
				revrotate(a);
				ft_printf("rrb\n");
			}
			push(a, b);
			ft_printf("pa\n");
		}
		else if (rot == 0 && a->top->content != max)
		{
			push(b, a);
			ft_printf("pb\n");
		}
	}
}

void	sort(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int i;
	int *delimiters;
	int number_chunks;

	chunk_size = a->size * 0.015 + 3.5;
	if (chunk_size < 4)
		chunk_size = 1;
	number_chunks = a->size / chunk_size;
	i = 0;
	delimiters = compute_delimiters(a, chunk_size);
	while (i < number_chunks -1)
	{
		send_b(a, b, i, i+1);
		get_back(a, b);
		++i;
	}
}

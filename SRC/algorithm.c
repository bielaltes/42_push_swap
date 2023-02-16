/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:07:36 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/16 17:51:08 by baltes-g         ###   ########.fr       */
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
	while (aux && aux != a->bot)
	{
		numbers[i] = aux->content;
		aux = aux->ant;
		++i;
	}
	numbers[i] = aux->content;
}

int	smart_rot(t_stack *a, int min, int max)
{
	int		sum;
	int		found;
	t_node	*aux;

	found = 0;
	aux = a->top;
	sum = 1;
	while (aux && aux != a->bot && !found)
	{
		if (aux->content >= min && aux->content <= max)
			found = sum;
		aux = aux->ant;
		++sum;
	}
	if (aux && !found)
	{
		if (aux->content >= min && aux->content <= max)
			found = sum;
	}
	if (!found)
		return (0);
	aux = a->bot;
	sum = 1;
	while (aux != a->top && sum < found)
	{
		if (aux->content >= min && aux->content <= max)
			return (RRA);
		aux = aux->next;
		++sum;
	}
	return (RA);
}

void	sort_array(int *numbers, int n)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (numbers[i] > numbers[j])
			{
				a = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = a;
			}
			j++;
		}
		++i;
	}
}

static void	fill_indx(t_stack *a, int *indx)
{
	fill_array(indx, a);
	sort_array(indx, a->size);
}

static void	send_b(t_stack *a, t_stack *b, int *indx, int i, int size)
{
	int	end;
	int	max;
	int	min;

	max = indx[(i -1) * size];
	min = indx[i * size];
	if (b->size == 0)
		min = indx[a->size -1];
	end = 1;
	while (end)
	{
		end = smart_rot(a, min, max);
		if (end == RA)
		{
			while (!(a->top->content <= max && a->top->content >= min))
			{
				rotate(a);
			}
			push(b, a);
			if (b->top->content > indx[i * size - (size / 2)])
				rotate(b);
		}
		else if (end == RRA)
		{
			while (!(a->top->content <= max && a->top->content >= min))
			{
				revrotate(a);
			}
			push(b, a);
			if (b->top->content > indx[i * size - (size / 2)])
				rotate(b);
		}
	}
}

static int	in_4(int n, int *max)
{
	if (n == max[0])
		return (1);
	if (n == max[1])
		return (1);
	if (n == max[2])
		return (1);
	if (n == max[3])
		return (1);
	return (0);
}

static void	get_back(t_stack *a, t_stack *b, int *indx, int i, int size)
{
	int	*max;
	int	rot;

	size = 0;
	indx[0] = i;
	while (b->size != 0)
	{
		if (b->size <= 2)
		{
			while (b->size != 0)
				push(a, b);
			sort2(a);
		}
		else
		{
			max = max4_stack(b);
			while ((rot = smart_rot(b, max[2], max[0])) != 0)
			{
				if (rot == RA)
				{
					while (!in_4(b->top->content, max))
					{
						rotate(b);
					}
					push(a, b);
					if (a->size > 1 && a->top->content == max[0]
						&& a->top->ant->content == max[1])
						swap(a);
					if (a->top->content <= max[2]
						&& smart_rot(b, max[1], max[0]) != 0)
						rotate(a);
				}
				else if (rot == RRA)
				{
					while (!in_4(b->top->content, max))
					{
						revrotate(b);
					}
					push(a, b);
					if (a->size > 1 && a->top->content == max[0]
						&& a->top->ant->content == max[1])
						swap(a);
					if (a->top->content <= max[2]
						&& smart_rot(b, max[1], max[0]) != 0)
						rotate(a);
				}
			}
			sort4_esp(a, max);
			free(max);
		}
	}
}

int	cp(int size)
{
	if (size <= 100)
		return (size / 3);
	else
		return (size / 6);
}

void	sort(t_stack *a, t_stack *b)
{
	int	*indx;
	int	chunk_size;
	int	chunks;
	int	i;

	if (a->size == 2)
		return (sort2(a));
	else if (a->size == 3)
		return (sort3(a));
	else if (a->size == 4)
		return (sort4(a, b));
	else if (a->size == 5)
		return (sort5(a, b));
	indx = malloc(sizeof(int) * a->size);
	fill_indx(a, indx);
	chunk_size = cp(a->size);
	if (chunk_size < 5)
		chunk_size = 3;
	chunks = a->size / chunk_size;
	i = chunks;
	while (i > 0)
	{
		send_b(a, b, indx, i, chunk_size);
		--i;
	}
	get_back(a, b, indx, i, chunk_size);
	free(indx);
}

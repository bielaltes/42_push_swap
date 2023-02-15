/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:07:36 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/14 11:30:50 by baltes-g         ###   ########.fr       */
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
	delimiters = malloc(sizeof(int)  * (a->size / chunk + 2));
	delimiters[a->size / chunk + 1] = -1;
	fill_array(numbers, a);
	sort_array(numbers, a->size);
	i = 0;
	while (i < (a->size / chunk))
	{
		delimiters[i] = numbers[i * chunk];
		++i;
	}
	delimiters[i] = numbers[a->size-1];
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

void	send_b(t_stack *a, t_stack *b, int max, int min)
{
	int end;
	//ft_printf("%d %d\n", min, max);
	end = 1;
	while (end)
	{
		end = smart_rot(a, min, max);
		//print_stack(a);
		//print_stack(b);
		//ft_printf("%d\n", end);
		if (end == RA)
		{
			while (!(a->top->content <= max && a->top->content >= min))
			{
				rotate(a);
			}
			push(b, a);
			if (b->top->content < (max-min)/2)
				rotate(b);
		}
		else if (end == RRA)
		{
			//ft_printf(" soc el top: %d %d, %d\n", a->top->content, min, max);
			while (!(a->top->content <= max && a->top->content >= min))
			{
				revrotate(a);
			}
			push(b, a);
			if (b->top->content < (max-min)/2)
				rotate(b);
		}
	}
}

static int	in_3(int n, int *max)
{
	if (n == max[0])
		return (1);
	if (n == max[1])
		return (1);
	//if (n == max[2])
		//return (1);
	return (0);
}

void get_back(t_stack *a, t_stack *b)
{
	int rot;
	int	*max;

	while (b->size != 0)
	{
		//print_stack(a);
		//print_stack(b);
		//ft_printf("\n");
		if (b->size <= 2)
		{
			while (b->size != 0)
				push(a, b);
			sort2(a);
		}
		else
		{
			max = max3_stack(b);
			//ft_printf("max:%d %d", max[2], max[0]);
			while ((rot = smart_rot(b, max[1], max[0])) != 0)
			{
				if (rot == RA)
				{
					while (!in_3(b->top->content, max))
					{
						rotate(b);
					}
					push(a, b);
				}
				else if (rot == RRA)
				{
					while (!in_3(b->top->content, max))
					{
						revrotate(b);
					}
					push(a, b);
				}
			}
			free(max);
			sort2(a);
		}
	}
}



void	sort(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int i;
	int *delimiters;
	int number_chunks;

	if (a->size == 2)
		return (sort2(a));
	else if (a->size == 3)
		return (sort3(a));
	else if(a->size == 4)
		return (sort4(a, b));
	else if (a->size == 5)
		return (sort5(a, b));
	chunk_size = a->size * 0.015 + 3.5;
	if (chunk_size < 4)
		chunk_size = 2;
	number_chunks = a->size / chunk_size + 1;
	i = 0;
	delimiters = compute_delimiters(a, chunk_size);
	//for (int k = 0; delimiters[k] != -1; ++k)
		//ft_printf("%d ", delimiters[k]);
	//write(1, "\n", 1);
	while (i < number_chunks)
	{
		send_b(a, b,delimiters[i], delimiters[i+1]);
		++i;
	}
	while (b->size != 0)
		get_back(a, b);
}

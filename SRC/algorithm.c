/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:07:36 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/20 19:10:21 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/push_swap.h"
#include "../libft/libft.h"

static void	send_b(t_stack *a, t_stack *b, int *indx, int *norm)
{
	int	end;
	int	max;
	int	min;

	max = indx[(norm[0] -1) * norm[1]];
	min = indx[norm[0] * norm[1]];
	if (b->size == 0)
		min = indx[a->size -1];
	end = smart_rot(a, min, max);
	while (end)
	{
		while (!(a->top->content <= max && a->top->content >= min))
		{
			if (end == RRA)
				revrotate(a);
			else
				rotate(a);
		}
		push(b, a);
		if (b->top->content > indx[norm[0] * norm[1] - (norm[1] / 2)])
			rotate(b);
		end = smart_rot(a, min, max);
	}
}

static void	get_back_aux(t_stack *a, t_stack *b, int *max, int rot)
{
	while (!in_4(b->top->content, max))
	{
		if (rot == RA)
			rotate(b);
		else
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

static void	get_back(t_stack *a, t_stack *b)
{
	int	*max;
	int	rot;

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
			rot = smart_rot(b, max[2], max[0]);
			while (rot != 0)
			{
				get_back_aux(a, b, max, rot);
				rot = smart_rot(b, max[2], max[0]);
			}
			sort4_esp(a, max);
			free(max);
		}
	}
}

static int	choose_size(int size)
{
	if (size <= 100)
		return (size / 3);
	else
		return (size / 6);
}

void	sort(t_stack *a, t_stack *b)
{
	int	*indx;
	int	chunks;
	int	norm[2];

	if (a->size == 2)
		return (sort2(a));
	else if (a->size == 3)
		return (sort3(a));
	else if (a->size == 4)
		return (sort4(a, b));
	else if (a->size == 5)
		return (sort5(a, b));
	indx = fill_indx(a);
	norm[1] = choose_size(a->size);
	if (norm[1] < 5)
		norm[1] = 3;
	chunks = a->size / norm[1];
	norm[0] = chunks;
	while (norm[0] > 0)
	{
		send_b(a, b, indx, norm);
		norm[0]--;
	}
	get_back(a, b);
	free(indx);
}

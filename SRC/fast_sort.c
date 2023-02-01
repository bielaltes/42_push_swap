/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:27:52 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/01 12:00:09 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/push_swap.h"
#include "../libft/libft.h"

void	sort2(t_stack *a)
{
	if (a->size >= 2)
	{
		if (a->top->content > a->top->ant->content)
			swap(a);
	}
}
void	sort3(t_stack *a)
{
	int *n;

	n = malloc(sizeof(int) * (a->size + 1));
	fill_array(n, a);
	if (sorted(a, 3))
		return ;
	if (n[0] < n[1] && n[0] < n[2] && n[1] > n[2])
	{
		revrotate(a);
		swap(a);
	}
	else if (n[0] > n[1] && n[0] < n[2] && n[1] < n[2])
		swap(a);
	else if (n[0] < n[1] && n[0] > n[2] && n[1] > n[2])
		revrotate(a);
	else if (n[1] < n[2] && n[0] > n[1] && n[0] > n[2])
		rotate(a);
	else if (n[1] > n[2] && n[0] > n[1] && n[0] > n[2])
	{
		rotate(a);
		swap(a);
	}
	free(n);
}

void	sort4(t_stack *a, t_stack *b)
{
	int	min;
	int	rot;

	if (sorted(a, 4))
		return ;
	min = min_stack(a);
	rot = smart_rot(a, min, min);
	if (min == a->top->content)
		push(b, a);
	else if (rot == RA)
	{
		while (a->top->content != min)
			rotate(a);
		push(b, a);
	}
	else if (rot == RRA)
	{
		while (a->top->content != min)
			revrotate(a);
		push(b, a);
	}
	sort3(a);
	push(a, b);
}

void	sort5(t_stack *a, t_stack *b)
{
	int	min;
	int	rot;

	if (sorted(a, 5))
		return ;
	min = min_stack(a);
	rot = smart_rot(a, min, min);
	if (min == a->top->content)
		push(b, a);
	else if (rot == RA)
	{
		while (a->top->content != min)
			rotate(a);
		push(b, a);
	}
	else if (rot == RRA)
	{
		while (a->top->content != min)
			revrotate(a);
		push(b, a);
	}
	sort4(a, b);
	push(a, b);
}
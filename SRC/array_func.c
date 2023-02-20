/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:04:43 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/20 18:58:34 by baltes-g         ###   ########.fr       */
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

int	*fill_indx(t_stack *a)
{
	int	*indx;

	indx = malloc(sizeof(int) * a->size);
	if (!indx)
		exit(2);
	fill_array(indx, a);
	sort_array(indx, a->size);
	return (indx);
}

int	in_4(int n, int *max)
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

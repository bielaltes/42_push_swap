/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:07:43 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/20 19:13:02 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/push_swap.h"
#include "../libft/libft.h"

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
	if (sum > a->size / 2 +1)
		return (RRA);
	return (RA);
}

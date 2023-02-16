/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:42:59 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/16 16:51:51 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/push_swap.h"
#include "../libft/libft.h"

static void	free_stack(t_stack *a)
{
	while (a->size != 0)
		pop(a);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	a;
	t_stack	b;

	if (!parse(argc, argv) || argc == 1)
		write(2, "Error\n", 6);
	else
	{
		init_stack(&a, 'a');
		init_stack(&b, 'b');
		i = argc -1;
		while (i > 0)
		{
			push_top(&a, atoi(argv[i]));
			--i;
		}
		if (!sorted(&a, argc -1))
			sort(&a, &b);
		free_stack(&a);
	}
}

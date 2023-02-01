/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:42:59 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/01 12:00:21 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/push_swap.h"
#include "../libft/libft.h"

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	if (!parse(argc, argv) || argc ==1)
		write(2, "Error\n", 6);
	else
	{
		init_stack(&a, 'a');
		init_stack(&b, 'b');
		//print_stack(&a);
		for (int i = argc-1; i > 0; --i)
			push_top(&a, atoi(argv[i]));
		sort(&a, &b);
		//print_stack(&a);
	}
}

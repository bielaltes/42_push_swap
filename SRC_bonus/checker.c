/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:43:27 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/15 17:33:32 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/push_swap.h"
#include "../libft/libft.h"

static int equal(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	return (ft_strncmp(s1, s2, ft_strlen(s1)));
}

static int	correct(char *cmd)
{
	if (equal(cmd, "sa") || equal(cmd, "sb") || equal(cmd, "ss"))
		return (1);
	else if (equal(cmd, "ra") || equal(cmd, "rb") || equal(cmd, "rr"))
		return (1);
	else if (equal(cmd, "rra") || equal(cmd, "rrb") || equal(cmd, "rrr"))
		return (1);
	else if (equal(cmd, "pa") || equal(cmd, "pb"))
		return (1);
	return (0);
}

static void exec(char *cmd, t_stack *a, t_stack *b)
{
	if (equal(cmd, "sa"))
		swap(a);
	else if (equal(cmd, "sb"))
		swap(b);
	else if (equal(cmd, "ss"))
		sswap(a, b);
	else if (equal(cmd, "pa"))
		push(a, b);
	else if (equal(cmd, "pb"))
		push(b, a);
	else if (equal(cmd, "ra"))
		rotate(a);
	else if (equal(cmd, "rb"))
		rotate(a);
	else if (equal(cmd, "rr"))
		rrotate(a, b);
	else if (equal(cmd, "rra"))
		revrotate(a);
	else if (equal(cmd, "rrb"))
		revrotate(a);
	else if (equal(cmd, "rrr"))
		revvrrotate(a, b);
}

static void exec_commands(t_stack *a, t_stack *b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (!correct(cmd))
			write(1, "Error\n", 3);
		else
			exec(cmd, a, b);
		free(cmd);
		cmd = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	t_stack	*aux;

	aux = &a;
	if (!parse(argc, argv) || argc == 1)
		write(1, "KO\n", 3);
	else
	{
		init_stack(&a, 'a');
		init_stack(&b, 'b');
		for (int i = argc-1; i > 0; --i)
			push_top(&a, atoi(argv[i]));
		exec_commands(&a, &b);
		if (sorted(&a, aux->size))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
}
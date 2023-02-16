/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:43:27 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/16 16:17:49 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/checker.h"
#include "../../libft/libft.h"

static int equal(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	return (ft_strncmp(s1, s2, ft_strlen(s1)));
}

static int	correct(char *cmd)
{
	if (equal(cmd, "sa\n") || equal(cmd, "sb\n") || equal(cmd, "ss\n"))
		return (1);
	else if (equal(cmd, "ra\n") || equal(cmd, "rb\n") || equal(cmd, "rr\n"))
		return (1);
	else if (equal(cmd, "rra\n") || equal(cmd, "rrb\n") || equal(cmd, "rrr\n"))
		return (1);
	else if (equal(cmd, "pa\n") || equal(cmd, "pb\n"))
		return (1);
	return (0);
}

static void exec(char *cmd, t_stack *a, t_stack *b)
{
	if (equal(cmd, "sa\n"))
		swap(a);
	else if (equal(cmd, "sb\n"))
		swap(b);
	else if (equal(cmd, "ss\n"))
		sswap(a, b);
	else if (equal(cmd, "pa\n"))
		push(a, b);
	else if (equal(cmd, "pb\n"))
		push(b, a);
	else if (equal(cmd, "ra\n"))
		rotate(a);
	else if (equal(cmd, "rb\n"))
		rotate(a);
	else if (equal(cmd, "rr\n"))
		rrotate(a, b);
	else if (equal(cmd, "rra\n"))
		revrotate(a);
	else if (equal(cmd, "rrb\n"))
		revrotate(a);
	else if (equal(cmd, "rrr\n"))
		revvrrotate(a, b);
}

static void exec_commands(t_stack *a, t_stack *b)
{
	char	*cmd;

	cmd = get_next_line(0);
	ft_printf("%s\n", cmd);
	while (cmd)
	{
		if (!correct(cmd))
		{
			write(2, "Error\n", 6);
			exit(2);
		}
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
		write(2, "Error\n", 6);
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
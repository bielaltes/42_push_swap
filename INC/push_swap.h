/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:12:22 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/01 11:13:05 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define RA 1
# define RRA 2
typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*ant;
}					t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bot;
	int				size;
	char			name;
}					t_stack;

int		parse(int argc, char **argv);
void	swap(t_stack *s);
void	sswap(t_stack *s1, t_stack *s2);
void	push(t_stack *s1, t_stack *s2);
void	rotate(t_stack *s);
void	rrotate(t_stack *s1, t_stack *s2);
void	revrotate(t_stack *s);
void	revvrrotate(t_stack *s1, t_stack *s2);
void	init_stack(t_stack *stack, char c);
void	push_top(t_stack *stack, int num);
void	pop(t_stack *stack);
int		min_stack(t_stack *stack);
int		max_stack(t_stack *stack);
int		*max3_stack(t_stack *stack);
void 	print_stack(t_stack *stack);
void	sort(t_stack *a, t_stack *b);
void	sort2(t_stack *a);
void	sort3(t_stack *a);
void	sort4(t_stack *a, t_stack *b);
void	sort5(t_stack *a, t_stack *b);
void	fill_array(int *n, t_stack*a);
int		smart_rot(t_stack *a, int min, int max);
int		sorted(t_stack *a, int n);

#endif
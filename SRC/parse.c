/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:48:13 by baltes-g          #+#    #+#             */
/*   Updated: 2023/01/28 18:59:53 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/push_swap.h"
#include "../libft/libft.h"

static int	check_numbers(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	return (i);
}

int	parse(int argc, char **argv)
{
	for (int i = 1;  i < argc; ++i)
	{
		int size = check_numbers(argv[i]);
		if (size == 0 || size > 10)
			return (0);
		if (size == 10 && ft_strncmp(argv[i], "2147483647", 10) > 0)
			return (0);
	}
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:48:13 by baltes-g          #+#    #+#             */
/*   Updated: 2023/02/16 16:49:00 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/push_swap.h"
#include "../libft/libft.h"

static int	check_repeated(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (i != j && ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

static int	check_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && (i != 0 || str[i] != '-'))
			return (0);
		else if (str[0] == '-' && ft_strlen(str) == 1)
			return (0);
		++i;
	}
	return (i);
}

int	parse(int argc, char **argv)
{
	int	i;
	int	size;

	i = 1;
	while (i < argc)
	{
		size = check_numbers(argv[i]);
		if (size == 0 || (size > 10 && argv[i][0] != '-') || size > 11)
			return (0);
		if (argv[i][0] != '-' && size == 10 &&
			ft_strncmp(argv[i], "2147483647", 10) > 0)
			return (0);
		if (argv[i][0] == '-' && size == 11 &&
			ft_strncmp(argv[i], "-2147483648", 11) > 0)
			return (0);
		++i;
	}
	return (check_repeated(argc, argv));
}

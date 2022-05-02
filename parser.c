/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:55:31 by rrangwan          #+#    #+#             */
/*   Updated: 2022/05/01 18:59:23 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	is_ints(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-')
			j++;
		while (j < ft_strlen(argv[i]))
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*ft_fill(int argc, char **argv, int *in_stack)
{
	int			i;
	long long	temp;

	i = 1;
	while (i < argc)
	{
		temp = ft_atoi(argv[i]);
		if (temp < 2147483647 && temp > -2147483648)
		{
			in_stack[i - 1] = (int) temp;
			i++;
		}
		else
			ft_error2(in_stack);
	}
	return (in_stack);
}

int	no_dup(int *in_stack, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (in_stack[i] == in_stack[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_parser(int argc, char **argv, int *in_stack)
{
	if (is_ints(argc, argv) != 0)
	{
		in_stack = ft_fill(argc, argv, in_stack);
		if (not_null(argv, argc - 1))
			ft_error2(in_stack);
		if (no_dup(in_stack, argc - 1))
			ft_rank(in_stack, argc - 1);
		else
			ft_error2(in_stack);
	}
	else
		ft_error2(in_stack);
}

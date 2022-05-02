/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:55:41 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/19 18:56:56 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	simple_sort(int *in_stack, int len, int *temp)
{
	int	t;
	int	i[3];

	i[0] = 0;
	while (i[0] < len)
	{
		temp[i[0]] = in_stack[i[0]];
		i[0]++;
	}
	i[0] = 0;
	while (i[0] < len)
	{
		i[1] = i[0] + 1;
		i[2] = i[0];
		while (i[1] < len)
		{
			if (temp[i[1]] < temp[i[2]])
				i[2] = i[1];
			i[1]++;
		}
		t = temp[i[2]];
		temp[i[2]] = temp[i[0]];
		temp[i[0]] = t;
		i[0]++;
	}
}

void	ft_rank(int *in_stack, int len)
{
	int	*temp;
	int	i[2];

	temp = malloc(sizeof(int) * len);
	i[0] = 0;
	simple_sort(in_stack, len, temp);
	while (i[0] < len)
	{
		i[1] = 0;
		while (i[1] < len)
		{
			if (in_stack[i[0]] == temp[i[1]])
			{
				in_stack[i[0]] = i[1] + 1;
				i[1] = len;
			}
			else
				i[1]++;
		}
		i[0]++;
	}
	free(temp);
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	ft_error2(int *stack)
{
	free (stack);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

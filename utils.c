/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:55:48 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/19 18:56:44 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	max(int *stack, int len)
{
	int	i;
	int	ret;
	int	max;

	i = 0;
	ret = 0;
	max = stack[0];
	while (i < len)
	{
		if (max <= stack[i])
		{
			max = stack[i];
			ret = i;
		}
		i++;
	}
	return (ret);
}

int	not_sorted_rev(int *in_stack, int len)
{
	int	i;

	if (len <= 1)
		return (0);
	i = 1;
	while (i < len)
	{
		if (in_stack[i] > in_stack[i - 1])
			return (1);
		i++;
	}
	return (0);
}

void	move_down(int *in_stack, int len)
{
	int	i;
	int	temp;
	int	tempi;

	i = 1;
	temp = in_stack[0];
	in_stack[0] = 0;
	while (i <= len)
	{
		tempi = in_stack[i];
		in_stack[i] = temp;
		i++;
		temp = tempi;
	}
}

void	move_up(int	*in_stack, int len)
{
	int	i;
	int	temp;
	int	tempi;

	i = len - 2;
	temp = in_stack[len - 1];
	in_stack[len - 1] = 0;
	while (i >= 0)
	{
		tempi = in_stack[i];
		in_stack[i] = temp;
		i--;
		temp = tempi;
	}
}

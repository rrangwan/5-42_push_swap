/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops3_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:55:08 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/19 16:09:23 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	bra(t_stacks *stacks)
{
	int	tempi;
	int	i;

	i = 0;
	if (stacks->len_a > 2)
	{
		tempi = stacks->stack_a[0];
		while (i < stacks->len_a - 1)
		{
			stacks->stack_a[i] = stacks->stack_a[i + 1];
			i++;
		}
		stacks->stack_a[stacks->len_a - 1] = tempi;
	}
}

void	brb(t_stacks *stacks)
{
	int	tempi;
	int	i;

	i = 0;
	if (stacks->len_b > 2)
	{
		tempi = stacks->stack_b[0];
		while (i < stacks->len_b - 1)
		{
			stacks->stack_b[i] = stacks->stack_b[i + 1];
			i++;
		}
		stacks->stack_b[stacks->len_b - 1] = tempi;
	}
}

void	brr(t_stacks *stacks)
{
	bra(stacks);
	brb(stacks);
}

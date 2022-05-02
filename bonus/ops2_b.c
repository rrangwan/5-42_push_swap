/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:55:04 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/19 16:08:45 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	brra(t_stacks *stacks)
{
	int	tempi;
	int	i;

	i = 1;
	if (stacks->len_a > 2)
	{
		tempi = stacks->stack_a[stacks->len_a - i];
		while (stacks->len_a - i > 0)
		{
			stacks->stack_a[stacks->len_a - i] = \
			stacks->stack_a[stacks->len_a - i - 1];
			i++;
		}
		stacks->stack_a[0] = tempi;
	}
}

void	brrb(t_stacks *stacks)
{
	int	tempi;
	int	i;

	i = 1;
	if (stacks->len_b > 2)
	{
		tempi = stacks->stack_b[stacks->len_b - i];
		while (stacks->len_b - i > 0)
		{
			stacks->stack_b[stacks->len_b - i] = \
			stacks->stack_b[stacks->len_b - i - 1];
			i++;
		}
		stacks->stack_b[0] = tempi;
	}
}

void	brrr(t_stacks *stacks)
{
	brra(stacks);
	brrb(stacks);
}

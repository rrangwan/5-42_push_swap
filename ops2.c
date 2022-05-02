/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:55:24 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/19 17:49:43 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rra(t_stacks *stacks)
{
	int	tempi;
	int	i;

	i = 1;
	if (stacks->len_a >= 2)
	{
		tempi = stacks->stack_a[stacks->len_a - i];
		while (stacks->len_a - i > 0)
		{
			stacks->stack_a[stacks->len_a - i] \
			= stacks->stack_a[stacks->len_a - i - 1];
			i++;
		}
		stacks->stack_a[0] = tempi;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stacks *stacks)
{
	int	tempi;
	int	i;

	i = 1;
	if (stacks->len_b >= 2)
	{
		tempi = stacks->stack_b[stacks->len_b - i];
		while (stacks->len_b - i > 0)
		{
			stacks->stack_b[stacks->len_b - i] \
			= stacks->stack_b[stacks->len_b - i - 1];
			i++;
		}
		stacks->stack_b[0] = tempi;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
	write(1, "rrr\n", 4);
}

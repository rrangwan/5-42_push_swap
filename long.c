/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42AbuDhabi.AE>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:54:45 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/30 00:10:00 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	long_a(t_stacks *stacks, int i)
{
	while (i > 0)
	{
		ra(stacks);
		i--;
	}
	pb(stacks);
}

void	long_b(t_stacks *stacks, int i)
{
	while (i < stacks->len_a)
	{
		rra(stacks);
		i++;
	}
	pb(stacks);
}

void	long1(t_stacks *stacks)
{
	int	i;

	while (stacks->len_b > 0)
	{
		i = max(stacks->stack_b, stacks->len_b);
		if (i <= stacks->len_b / 2)
		{
			while (i > 0)
			{
				rb(stacks);
				i--;
			}
			pa(stacks);
		}
		else
		{
			while (i < stacks->len_b)
			{
				rrb(stacks);
				i++;
			}
			pa(stacks);
		}
	}
}

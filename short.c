/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:55:44 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/25 03:01:11 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_sort3(t_stacks *stacks)
{
	if (not_sorted(stacks->stack_a, stacks->len_a))
	{
		if (stacks->stack_a[0] < stacks->stack_a[2] && stacks->stack_a[1] \
		< stacks->stack_a[0])
			sa(stacks);
		else if (stacks->stack_a[0] < stacks->stack_a[1] && stacks->stack_a[0] \
		> stacks->stack_a[2])
			rra(stacks);
		else if (stacks->stack_a[0] > stacks->stack_a[2] && stacks->stack_a[1] \
		< stacks->stack_a[2])
			ra(stacks);
		else if (stacks->stack_a[0] > stacks->stack_a[1] && stacks->stack_a[1] \
		> stacks->stack_a[2])
		{
			sa(stacks);
			rra(stacks);
		}
		else if (stacks->stack_a[0] < stacks->stack_a[2] && stacks->stack_a[2] \
		< stacks->stack_a[1])
		{
			sa(stacks);
			ra(stacks);
		}
	}
}

void	ft_sort4(t_stacks *stacks, int x)
{
	int	i;

	i = 0;
	while (stacks->stack_a[i] != x)
		i++;
	if (i <= 1)
	{
		i++;
		while (--i > 0)
			ra(stacks);
	}
	else
	{
		i--;
		while (++i < stacks->len_a)
			rra(stacks);
	}
	if (not_sorted(stacks->stack_a, stacks->len_a))
	{
		pb(stacks);
		ft_sort3(stacks);
		pa(stacks);
	}
}

void	ft_sort5(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (stacks->stack_a[i] != 1)
		i++;
	if (i <= 2)
	{
		i++;
		while (--i > 0)
			ra(stacks);
	}
	else
	{
		i--;
		while (++i < stacks->len_a)
			rra(stacks);
	}
	if (not_sorted(stacks->stack_a, stacks->len_a))
	{
		pb(stacks);
		ft_sort4(stacks, 2);
		pa(stacks);
	}
}

void	short_sort(t_stacks *stacks)
{
	if (stacks->len == 2)
		sa(stacks);
	if (stacks->len == 3)
		ft_sort3(stacks);
	if (stacks->len == 4)
		ft_sort4(stacks, 1);
	if (stacks->len == 5)
		ft_sort5(stacks);
}

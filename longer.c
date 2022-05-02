/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:45:34 by rrangwan          #+#    #+#             */
/*   Updated: 2022/05/01 16:46:22 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	longer_sort(t_stacks *stacks, int pivot)
{
	int	i[2];

	i[0] = 0;
	i[1] = stacks->len_a - 1;
	while (stacks->stack_a[i[0]] != stacks->stack_a[i[1]])
	{
		i[0] = 0;
		i[1] = stacks->len_a - 1;
		while (stacks->stack_a[i[0]] > pivot)
			i[0]++;
		while (stacks->stack_a[i[1]] > pivot && i[0] <= i[1])
			i[1]--;
		long_sort1(stacks, i[0], i[1]);
	}
}

void	long_sort1(t_stacks *stacks, int i, int j)
{
	if (i <= (stacks->len_a - j) - 1)
		long_a(stacks, i);
	else
		long_b(stacks, j);
}

void	long_sort(t_stacks *stacks, int e)
{
	int	d;
	int	l;
	int	i;

	i = 1;
	d = (stacks->len_a / e);
	l = d;
	longer_sort(stacks, l);
	while (i <= e)
	{
		l += d;
		if (not_sorted(stacks->stack_a, stacks->len_a))
			longer_sort(stacks, l);
		i++;
	}
}

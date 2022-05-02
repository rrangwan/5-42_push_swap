/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:55:31 by rrangwan          #+#    #+#             */
/*   Updated: 2022/05/01 16:47:59 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_push_swap(int len, int *in_stack)
{
	t_stacks	*stacks;
	int			i;

	i = 0;
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		ft_error2(in_stack);
	stacks->len = len;
	stacks->len_a = len;
	stacks->len_b = 0;
	stacks->stack_a = malloc((len * sizeof(int)));
	stacks->stack_b = malloc((len * sizeof(int)));
	while (i < len)
	{
		stacks->stack_a[i] = in_stack[i];
		i++;
	}
	ft_ps(stacks, len);
	free (stacks->stack_a);
	free (stacks->stack_b);
	free (stacks);
}

void	ft_ps(t_stacks *stacks, int len)
{
	if (len < 6)
		short_sort(stacks);
	else if (len >= 6 && len < 100)
	{
		long_sort(stacks, 2);
		long1(stacks);
	}
	else if (len >= 100 && len < 500)
	{
		long_sort(stacks, 6);
		long1(stacks);
	}
	else if (len >= 500)
	{
		long_sort(stacks, 15);
		long1(stacks);
	}
}

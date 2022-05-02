/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:55:20 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/19 15:55:21 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sa(t_stacks *stacks)
{
	int	temp;

	if (stacks->len_a >= 1)
	{
		temp = stacks->stack_a[0];
		stacks->stack_a[0] = stacks->stack_a[1];
		stacks->stack_a[1] = temp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_stacks *stacks)
{
	int	temp;

	if (stacks->len_b > 1)
	{
		temp = stacks->stack_b[0];
		stacks->stack_b[0] = stacks->stack_b[1];
		stacks->stack_b[1] = temp;
		write(1, "sb\n", 3);
	}
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
	write(1, "ss\n", 3);
}

void	pa(t_stacks *stacks)
{
	int	temp;

	temp = stacks->stack_b[0];
	move_up(stacks->stack_b, stacks->len_b);
	stacks->len_b--;
	move_down(stacks->stack_a, stacks->len_a);
	stacks->stack_a[0] = temp;
	stacks->len_a++;
	write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks)
{
	int	temp;

	temp = stacks->stack_a[0];
	move_up(stacks->stack_a, stacks->len_a);
	stacks->len_a--;
	move_down(stacks->stack_b, stacks->len_b);
	stacks->stack_b[0] = temp;
	stacks->len_b++;
	write(1, "pb\n", 3);
}

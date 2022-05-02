/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:55:01 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/19 15:55:02 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

void	bsa(t_stacks *stacks)
{
	int	temp;

	if (stacks->len_a >= 1)
	{
		temp = stacks->stack_a[0];
		stacks->stack_a[0] = stacks->stack_a[1];
		stacks->stack_a[1] = temp;
	}
}

void	bsb(t_stacks *stacks)
{
	int	temp;

	if (stacks->len_b > 1)
	{
		temp = stacks->stack_b[0];
		stacks->stack_b[0] = stacks->stack_b[1];
		stacks->stack_b[1] = temp;
	}
}

void	bss(t_stacks *stacks)
{
	bsa(stacks);
	bsb(stacks);
}

void	bpa(t_stacks *stacks)
{
	int	temp;

	temp = stacks->stack_b[0];
	move_up(stacks->stack_b, stacks->len_b);
	stacks->len_b--;
	move_down(stacks->stack_a, stacks->len_a);
	stacks->stack_a[0] = temp;
	stacks->len_a++;
}

void	bpb(t_stacks *stacks)
{
	int	temp;

	temp = stacks->stack_a[0];
	move_up(stacks->stack_a, stacks->len_a);
	stacks->len_a--;
	move_down(stacks->stack_b, stacks->len_b);
	stacks->stack_b[0] = temp;
	stacks->len_b++;
}

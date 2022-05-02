/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:54:54 by rrangwan          #+#    #+#             */
/*   Updated: 2022/05/01 18:48:02 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

int	main(int argc, char **argv)
{
	int		*in_stack;
	int		len;
	char	**temp;

	len = argc - 1;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		len = ft_cnt_wrds(argv[1], ' ');
	}
	in_stack = (int *)malloc(sizeof(int) * len + 1);
	if (!in_stack)
		ft_error();
	if (argc == 2)
		ft_parser(len + 1, temp, in_stack);
	else
		ft_parser(argc, argv, in_stack);
	ft_ps_bonus(len, in_stack);
	free (in_stack);
	return (0);
}

void	ft_ps_bonus(int len, int *in_stack)
{
	t_stacks	*s_bonus;
	int			i;

	i = 0;
	s_bonus = malloc(sizeof(t_stacks));
	if (!s_bonus)
		ft_error2(in_stack);
	s_bonus->len = len;
	s_bonus->len_a = len;
	s_bonus->len_b = 0;
	s_bonus->stack_a = malloc((len * sizeof(int)));
	s_bonus->stack_b = malloc((len * sizeof(int)));
	while (i < len)
	{
		s_bonus->stack_a[i] = in_stack[i];
		i++;
	}
	checker(s_bonus);
	final_check(s_bonus);
	free (s_bonus->stack_a);
	free (s_bonus->stack_b);
	free (s_bonus);
}

void	ex_ps(char *str, t_stacks *stack)
{
	if ((ft_strncmp(str, "ra\n", 3) == 0))
		bra(stack);
	else if ((ft_strncmp(str, "rb\n", 3) == 0))
		brb(stack);
	else if ((ft_strncmp(str, "rr\n", 3) == 0))
		brr(stack);
	else if ((ft_strncmp(str, "rra\n", 4) == 0))
		brra(stack);
	else if ((ft_strncmp(str, "rrb\n", 4) == 0))
		brrb(stack);
	else if ((ft_strncmp(str, "rrr\n", 4) == 0))
		brrr(stack);
	else if ((ft_strncmp(str, "pa\n", 3) == 0))
		bpa(stack);
	else if ((ft_strncmp(str, "pb\n", 3) == 0))
		bpb(stack);
	else if ((ft_strncmp(str, "sa\n", 3) == 0))
		bsa(stack);
	else if ((ft_strncmp(str, "sb\n", 3) == 0))
		bsb(stack);
	else if ((ft_strncmp(str, "ss\n", 3) == 0))
		bss(stack);
}

void	final_check(t_stacks *stack)
{
	if (not_sorted(stack->stack_a, stack->len_a) || (stack->len_b != 0))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

void	checker(t_stacks *stack)
{
	char	*str;

	str = gnl(0);
	while (str != NULL)
	{
		if (!(check_str(str)))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		else
			ex_ps(str, stack);
		str = gnl(0);
	}
}

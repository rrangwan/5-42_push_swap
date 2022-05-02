/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:55:16 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/20 03:12:46 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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
	if (not_sorted(in_stack, len))
		ft_push_swap(len, in_stack);
	free (in_stack);
	return (0);
}

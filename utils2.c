/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:55:51 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/19 19:03:51 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int	ft_isspace(char s)
{
	if (s == ' ' || s == '\f' || s == '\n' || s == '\r' \
			|| s == '\t' || s == '\v')
		return (1);
	return (0);
}

long long	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long long	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		ret = (ret * 10) + (str[i] - '0');
		i++;
	}
	return (sign * ret);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

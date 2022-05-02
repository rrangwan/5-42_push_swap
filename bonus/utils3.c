/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:55:11 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/20 01:40:48 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

char	*ft_strchr(char *s, int c)
{
	char			a;
	unsigned int	i;

	a = (char)c;
	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (s[i] != '\0')
	{
		if (s[i] == a)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((unsigned char)s1[i] == (unsigned char)s2[i]) && (i < n) && \
			((unsigned char)s1[i] != '\0') && ((unsigned char)s2[i] != '\0'))
		i++;
	if (i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_str(char *str)
{
	int	ret;

	ret = 0;
	if ((ft_strncmp(str, "ra\n", 3) == 0) || (ft_strncmp(str, "rb\n", 3) == 0) || \
	(ft_strncmp(str, "rr\n", 3) == 0))
		ret = 1;
	if ((ft_strncmp(str, "pa\n", 3) == 0) || (ft_strncmp(str, "pb\n", 3) == 0))
		ret = 1;
	if ((ft_strncmp(str, "rra\n", 4) == 0) || (ft_strncmp(str, "rrb\n", 4) == 0) \
	|| (ft_strncmp(str, "rrr\n", 4) == 0))
		ret = 1;
	if ((ft_strncmp(str, "sa\n", 3) == 0) || (ft_strncmp(str, "sb\n", 3) == 0) || \
	(ft_strncmp(str, "ss\n", 3) == 0))
		ret = 1;
	return (ret);
}

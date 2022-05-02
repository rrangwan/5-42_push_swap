/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:16:13 by rrangwan          #+#    #+#             */
/*   Updated: 2022/04/20 02:42:44 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	ft_cnt_wrds(char *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

static char	*ft_wrd_posi(char *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[j] == c && s[j + 1] == c)
		j++;
	while (s[j + 1] != '\0')
	{
		if (i == 0 && s[j] != c && j == 0)
			return ((char *)&s[j]);
		if ((s[j] == c && s[j + 1] != c))
			return ((char *)&s[j + 1]);
		while (s[j + 1] == c && s[j + 2] == c)
			j++;
		j++;
	}
	return ((char *)s);
}

static void	ft_freem(char **wrd, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(wrd[j]);
		j++;
	}
	free(wrd);
}

static char	*ft_wrd_get(char *s, char c, char **str, int i)
{
	char	*wrd;
	int		j;
	int		len;

	len = 0;
	j = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	wrd = (char *)malloc(sizeof (char) * (len + 1));
	if (!wrd)
	{
		ft_freem(str, i);
		return (NULL);
	}
	while (j < len)
	{
		wrd[j] = s[j];
		j++;
	}
	wrd[j] = '\0';
	return (wrd);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	char	*next_wrd;
	int		i;
	int		words;

	if (!s)
		return (NULL);
	i = 0;
	next_wrd = (char *)s;
	words = ft_cnt_wrds(s, c);
	str = (char **)malloc(sizeof(char *) * (words + 2));
	if (!str)
		return (NULL);
	str[0] = "temp";
	while (i < words)
	{
		next_wrd = ft_wrd_posi(next_wrd, c, i);
		str[i + 1] = ft_wrd_get((char *)next_wrd, c, str, i);
		if (!str[i + 1])
			return (NULL);
		i++;
	}
	str[i + 1] = NULL;
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:54:57 by rrangwan          #+#    #+#             */
/*   Updated: 2022/05/01 18:38:31 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push.h"

char	*gnl(int fd)
{
	int		i[2];
	char	c;
	char	*buffer;

	i[0] = 0;
	buffer = malloc(10);
	if (!buffer)
		return (NULL);
	i[1] = read(fd, &c, 1);
	while (i[1] > 0)
	{
		buffer[i[0]] = c;
		if (c == '\n')
			break ;
		i[0]++;
		i[1] = read(fd, &c, 1);
	}
	if ((!buffer[i[0] - 1] && !i[1]) || i[1] == -1)
	{
		free(buffer);
		return (NULL);
	}
	i[0]++;
	buffer[i[0]] = '\0';
	return (buffer);
}

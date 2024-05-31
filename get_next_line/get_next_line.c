/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 04:00:46 by jubaldo           #+#    #+#             */
/*   Updated: 2024/05/31 14:04:13 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*handle_end_of_line(int depth, int *ret)
{
	char	*line;

	line = malloc(sizeof(char) * (depth + 1));
	if (!line)
	{
		*ret = -1;
		return (NULL);
	}
	line[depth] = '\0';
	return (line);
}

static char	*process_next_char(int depth, int *ret, int fd, char current_char)
{
	char	*next_line;

	next_line = recurs(depth + 1, ret, fd);
	if (!next_line)
		return (NULL);
	next_line[depth] = current_char;
	return (next_line);
}

char	*recurs(int depth, int *ret, int fd)
{
	char	buff[1];
	int		files;

	files = read(fd, buff, 1);
	if (files <= 0)
	{
		if (files == 0)
			*ret = 0;
		else
			*ret = -1;
		return (NULL);
	}
	if (buff[0] == '\n' || buff[0] == '\0')
		return (handle_end_of_line(depth, ret));
	else
		return (process_next_char(depth, ret, fd, buff[0]));
}

int	get_next_line(int fd, char **line)
{
	int	ret;

	ret = 1;
	*line = recurs(0, &ret, fd);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:47:59 by jomanuel          #+#    #+#             */
/*   Updated: 2024/11/24 21:47:59 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			chars_read;

	line = NULL;
	chars_read = 1;
	while (fd >= 0 && fd < FOPEN_MAX && BUFFER_SIZE > 0 && chars_read > 0)
	{
		if (buff[fd][0])
		{
			line = join_and_clean_buff(line, buff[fd]);
			if (!line)
				return (NULL);
			if (line[ft_strlen(line, '\n') - 1] == '\n')
				break ;
		}
		else
		{
			chars_read = read(fd, buff[fd], BUFFER_SIZE);
			if (chars_read < 0)
				return (free(line), NULL);
			buff[fd][chars_read] = '\0';
		}
	}
	return (line);
}

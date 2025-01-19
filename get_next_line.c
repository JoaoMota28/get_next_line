/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:07:15 by jomanuel          #+#    #+#             */
/*   Updated: 2024/11/24 19:07:15 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			chars_read;

	line = NULL;
	chars_read = 1;
	while (fd >= 0 && BUFFER_SIZE > 0 && chars_read > 0)
	{
		if (buff[0])
		{
			line = join_and_clean_buff(line, buff);
			if (!line)
				return (NULL);
			if (line[ft_strlen(line, '\n') - 1] == '\n')
				break ;
		}
		else
		{
			chars_read = read(fd, buff, BUFFER_SIZE);
			if (chars_read < 0)
				return (free(line), NULL);
			buff[chars_read] = '\0';
		}
	}
	return (line);
}

/*int main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}*/

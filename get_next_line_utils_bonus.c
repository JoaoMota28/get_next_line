/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomanuel <jomanuel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:48:38 by jomanuel          #+#    #+#             */
/*   Updated: 2024/11/24 21:48:38 by jomanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s, char del)
{
	size_t	counter;

	counter = 0;
	if (!s)
		return (0);
	while (s[counter] && s[counter] != del)
		counter++;
	if (s[counter] == '\n')
		counter++;
	return (counter);
}

char	*join_and_clean_buff(char *line, char *buff)
{
	char	*new_line;
	size_t	len_line;
	size_t	len_buff;
	size_t	i;

	i = 0;
	len_line = ft_strlen(line, '\0');
	len_buff = ft_strlen(buff, '\n');
	new_line = malloc((len_line + len_buff + 1) * sizeof(char));
	if (!new_line)
		return (free(line), NULL);
	new_line[len_line + len_buff] = '\0';
	ft_strlcpy(new_line, line, len_line);
	ft_strlcpy(new_line + len_line, buff, len_buff);
	free(line);
	while (buff[len_buff + i])
	{
		buff[i] = buff[len_buff + i];
		i++;
	}
	buff[i] = '\0';
	return (new_line);
}

void	ft_strlcpy(char *dest, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}

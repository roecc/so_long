/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:51:36 by ligabrie          #+#    #+#             */
/*   Updated: 2023/02/16 19:54:03 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_buff(int fd, char *s_buff)
{
	char	*tmp;
	int		bytes_read;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
	{
		free (s_buff);
		return (NULL);
	}
	bytes_read = 1;
	while (check_buff(s_buff) == -1 && bytes_read)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (tmp);
			free (s_buff);
			return (NULL);
		}
		tmp[bytes_read] = '\0';
		s_buff = str_join(s_buff, tmp);
	}
	free (tmp);
	return (s_buff);
}

char	*extract_next(char *s_buff)
{
	int		i;
	int		n_dex;
	char	*tmp;

	n_dex = check_buff(s_buff);
	if (n_dex < 0)
		if (s_buff)
			n_dex = ft_strlen(s_buff) - 1;
	tmp = (char *)malloc(sizeof(char) * (n_dex + 2));
	if (!tmp)
	{
		free (s_buff);
		return (NULL);
	}
	i = 0;
	while (i <= n_dex)
	{
		tmp[i] = s_buff[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*cut_buff(char *s_buff, char *next)
{
	char	*tmp;
	int		i;
	int		pos;

	if (!s_buff)
		return (NULL);
	pos = ft_strlen(next) - 1;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s_buff) - pos));
	if (!tmp)
	{
		free (s_buff);
		return (NULL);
	}
	pos++;
	i = pos;
	while (s_buff[i])
	{
		tmp[i - pos] = s_buff[i];
		i++;
	}
	tmp[i - pos] = '\0';
	free (s_buff);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*s_buff[4096];
	char		*next;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	s_buff[fd] = read_to_buff(fd, s_buff[fd]);
	next = extract_next (s_buff[fd]);
	s_buff[fd] = cut_buff (s_buff[fd], next);
	if (s_buff[fd])
	{
		if (s_buff[fd][0] == '\0')
		{
			free(s_buff[fd]);
			s_buff[fd] = NULL;
		}
	}
	if (next[0] == '\0')
	{
		free(next);
		return (NULL);
	}
	return (next);
}

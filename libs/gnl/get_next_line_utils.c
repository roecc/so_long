/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:51:30 by ligabrie          #+#    #+#             */
/*   Updated: 2023/02/16 18:01:56 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_buff(char *s_buff)
{
	int	i;

	if (!s_buff)
		return (-1);
	i = 0;
	while (s_buff[i])
	{
		if (s_buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

long int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*str_join(char *s0, char *s1)
{
	char	*tmp;
	int		s0_len;
	int		s1_len;
	int		i;

	if (!s0)
	{
		s0 = (char *)malloc(sizeof(char) * 1);
		s0[0] = '\0';
	}
	if (!s1)
		return (s0);
	s0_len = ft_strlen(s0);
	s1_len = ft_strlen(s1);
	tmp = (char *)malloc(sizeof(char) * (s0_len + s1_len + 1));
	i = -1;
	while (s0[++i])
		tmp[i] = s0[i];
	i--;
	while (s1[++i - s0_len])
		tmp[i] = s1[i - s0_len];
	tmp[i] = '\0';
	free(s0);
	return (tmp);
}

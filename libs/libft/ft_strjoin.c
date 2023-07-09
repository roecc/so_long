/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:04:20 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/09 13:29:19 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	long unsigned int	i;
	long unsigned int	s1len;
	long unsigned int	s2len;
	char				*dest;	

	s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	dest = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	s1len = i;
	i = 0;
	while (s2[i] != '\0')
	{
		dest[i + s1len] = s2[i];
		i++;
	}
	dest[i + s1len] = '\0';

	//mod
	free(s1);
	free(s2);
	//!mod
	return (dest);
}

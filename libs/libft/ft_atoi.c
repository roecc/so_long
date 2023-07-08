/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:21:32 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/05 11:41:56 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//modified
long int	ft_atoi(const char *str)
{
	long int	number;
	int			i;
	int			sign;

	number = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	if (str[i])
		return (2147483648);
	return (number * sign);
}

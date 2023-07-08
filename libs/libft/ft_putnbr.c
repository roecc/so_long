/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:30:38 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/08 19:31:13 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n, int fd)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		len = ft_putstr("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			len++;
			ft_putchar('-', fd);
			n = n * -1;
		}
		if (n > 9)
			len += ft_putnbr(n / 10, fd);
		len += ft_putchar((n % 10) + '0', fd);
	}
	return (len);
}

int	ft_putui(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n > 9)
		len = ft_putnbr(n / 10, fd);
	ft_putchar((n % 10) + '0', fd);
	len++;
	return (len);
}

int	ft_put_hex(size_t nbr, char	*digits)
{
	int	len;
	int	c;

	len = 0;
	if (nbr > 15)
		len = ft_put_hex(nbr / 16, digits);
	c = nbr % 16;
	ft_putchar(digits[c], 1);
	len++;
	return (len);
}

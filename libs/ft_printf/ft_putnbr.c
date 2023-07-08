/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:30:38 by ligabrie          #+#    #+#             */
/*   Updated: 2023/03/01 16:33:38 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		len = ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			len++;
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n > 9)
			len += ft_putnbr_fd(n / 10, fd);
		len += ft_putchar_fd((n % 10) + '0', fd);
	}
	return (len);
}

int	ft_putui_fd(unsigned int n, int fd)
{
	int	len;

	len = 0;
	if (n > 9)
		len = ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
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
	ft_putchar_fd(digits[c], 1);
	len++;
	return (len);
}

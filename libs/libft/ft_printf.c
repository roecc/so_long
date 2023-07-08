/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:16:12 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/08 19:30:05 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_percent(const char *s)
{
	int	i;
	int	nb_percent;
	int	pps;

	i = -1;
	nb_percent = 0;
	pps = 0;
	while (s[++i])
	{
		if (s[i] == '%' && pps == 0)
		{
			pps = -1;
			nb_percent++;
		}
		else
			pps = 0;
	}
	if (pps == -1)
		return (-1);
	return (nb_percent);
}

char	find_cmd_char(const char *s, int loc)
{
	int	i;
	int	nb_percent;
	int	pps;

	i = -1;
	nb_percent = 0;
	pps = 0;
	while (s[++i])
	{
		if (pps == -1 && nb_percent == loc)
			return (s[i]);
		if (s[i] == '%' && pps == 0)
		{
			pps = -1;
			nb_percent++;
		}
		else
			pps = 0;
	}
	if (pps == -1)
		return (-1);
	return (nb_percent);
}

int	func_switch(va_list valist, const char c)
{
	int	len;

	len = -2;
	if (c == 'c')
		len += ft_putchar(va_arg(valist, int), 1);
	else if (c == 's')
		len += ft_putstr(va_arg(valist, char *), 1);
	else if (c == 'p')
		len += ft_put_ptr (va_arg(valist, size_t));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(valist, int), 1);
	else if (c == 'u')
		len += ft_putui(va_arg(valist, unsigned int), 1);
	if (c == 'x')
		len += ft_put_hex(va_arg(valist, unsigned int), "0123456789abcdef");
	if (c == 'X')
		len += ft_put_hex(va_arg(valist, unsigned int), "0123456789ABCDEF");
	if (c == '%')
		len += ft_putchar('%', 1);
	return (len);
}

int	ft_printf(const char *cs, ...)
{
	va_list	valist;
	int		nb_var;
	int		i;
	int		len;

	nb_var = count_percent(cs);
	if (nb_var == -1)
		return (-1);
	va_start(valist, cs);
	len = 0;
	i = -1;
	while (cs[++i])
	{
		if (cs[i] == '%')
			len += func_switch(valist, cs[++i]);
		else
			write(1, &cs[i], 1);
	}
	va_end(valist);
	return (i + len);
}

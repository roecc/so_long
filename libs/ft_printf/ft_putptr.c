/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:32:06 by ligabrie          #+#    #+#             */
/*   Updated: 2023/03/01 16:37:30 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(size_t ptr)
{
	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	return (ft_putstr_fd("0x", 1) + ft_put_hex(ptr, "0123456789abcdef"));
}

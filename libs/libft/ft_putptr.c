/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:32:06 by ligabrie          #+#    #+#             */
/*   Updated: 2023/07/08 19:31:11 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_ptr(size_t ptr)
{
	if (!ptr)
		return (ft_putstr("(nil)", 1));
	return (ft_putstr("0x", 1) + ft_put_hex(ptr, "0123456789abcdef"));
}

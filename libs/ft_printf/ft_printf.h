/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:13:33 by ligabrie          #+#    #+#             */
/*   Updated: 2023/03/01 16:33:35 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

extern int	ft_printf(const char *cs, ...);
extern int	ft_putchar_fd(char c, int fd);
extern int	ft_putstr_fd(char *s, int fd);
extern int	ft_putnbr_fd(int n, int fd);
extern int	ft_putui_fd(unsigned int n, int fd);
extern int	ft_put_hex(size_t nbr, char	*digits);
extern int	ft_put_ptr(size_t ptr);

#endif
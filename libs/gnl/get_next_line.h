/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ligabrie <ligabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:55:09 by ligabrie          #+#    #+#             */
/*   Updated: 2023/02/16 19:55:59 by ligabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

extern char		*get_next_line(int fd);
extern int		check_buff(char *s_buff);
extern long int	ft_strlen(char *s);
extern char		*str_join(char *s0, char *s1);
extern char		*read_to_buff(int fd, char *s_buff);
extern char		*extract_next(char *s_buff);
extern char		*cut_buff(char *s_buff, char *next);
#endif

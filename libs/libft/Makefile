# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: admin <admin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 13:45:09 by admin             #+#    #+#              #
#    Updated: 2023/07/08 19:31:14 by admin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CCFLAG = -Wall -Wextra -Werror

AR = ar

ARFLAG = crs

SRCS_A = \
ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memset.c \
ft_toupper.c \
ft_tolower.c \
ft_strlen.c \
ft_memcpy.c \
ft_memmove.c \
ft_strchr.c \
ft_memchr.c \
ft_strrchr.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_strncmp.c \
ft_strrchr.c \
ft_strjoin.c \
ft_split.c \
ft_substr.c \
ft_strnstr.c \
ft_memcmp.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putnbr_fd.c \
ft_putendl_fd.c \
ft_strdup.c \
ft_itoa.c \
ft_striteri.c \
ft_strmapi.c \
ft_strtrim.c \
get_next_line.c \
get_next_line_utils.c \
ft_printf.c \
ft_putnbr.c \
ft_putptr.c \
ft_putstr.c

BONUS = \
ft_lstadd_back_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstdelone_bonus.c \
ft_lstiter_bonus.c \
ft_lstclear_bonus.c \
ft_lstlast_bonus.c \
ft_lstmap_bonus.c \
ft_lstnew_bonus.c \
ft_lstsize_bonus.c

SRCS = $(SRCS_A)

OBJS = $(SRCS:.c=.o)
OBJS_B = $(BONUS:.c=.o)

all: $(NAME)

bonus: $(OBJS) $(OBJS_B)
	$(AR) $(ARFLAG) $(NAME) $^

$(NAME): $(OBJS)
	$(AR) $(ARFLAG) $@ $^

%.o: %.c
	$(CC) $(CCFLAG) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
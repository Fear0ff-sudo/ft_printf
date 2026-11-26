# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amanet <amanet@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/11 22:29:08 by amanet            #+#    #+#              #
#    Updated: 2026/11/26 19:44:37 by amanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIBFT = libft/libft.a

SRCS = ft_printf.c \
	ft_putchar_cnt.c \
	ft_put_hexa_low.c \
	ft_put_hexa_up.c \
	ft_putnbr_cnt.c \
	ft_putstr_cnt.c \
	ft_put_unsigned_int.c \
	ft_putvoid.c \
	ft_bin_reverse.c \
	ft_to_bin.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT): libft/Makefile libft/libft.h
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS) 

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re

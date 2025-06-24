# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 12:05:27 by abougrai          #+#    #+#              #
#    Updated: 2024/02/25 23:06:55 by abougrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRC			= ft_putchar.c ft_printf.c ft_putnbr_adress.c ft_putnbr_decimal.c \
			ft_putnbr_lohexabase.c ft_putnbr_unsigned.c ft_putnbr_uphexabase.c \
			print_adress.c print_char.c print_digit.c print_lohexa.c print_percent.c \
			print_str.c print_unsigned.c print_uphexa.c main.c
OBJ			= $(SRC:.c=.o)
CC			= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f


all:			$(NAME)

$(NAME) :		$(OBJ)
				ar rcs $(NAME) $(OBJ)

clean :
				$(RM) $(OBJ)

fclean :			clean
	$(RM) $(NAME) main

re :				fclean $(NAME)

main:		$(NAME) main.c
			$(CC) $(CFLAGS) -o main main.c $(NAME)

exe:		main
			./main

.PHONY :			all clean fclean re bonus main exe

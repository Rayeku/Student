# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 11:56:48 by abougrai          #+#    #+#              #
#    Updated: 2023/11/15 13:47:51 by abougrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a
SRC				=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memcpy.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_strlcat.c ft_striteri.c ft_strncmp.c ft_substr.c ft_atoi.c  \
					ft_itoa.c ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c ft_strjoin.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c ft_strmapi.c ft_strtrim.c ft_isalpha.c
OBJ				= $(SRC:.c=.o)
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f
BONUS			=	ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c
BONUS_OBJS		= $(BONUS:.c=.o)

all:			$(NAME)

$(NAME) :		$(OBJ)
				ar rcs $(NAME) $(OBJ)

clean :
				$(RM) $(OBJ)

fclean :			clean
				$(RM) $(NAME)

re :				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY :			all clean fclean re bonus
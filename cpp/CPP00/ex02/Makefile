# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 07:02:09 by abougrai          #+#    #+#              #
#    Updated: 2024/05/01 13:05:12 by abougrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= TheJob
SRCS			= 	Account.cpp tests.cpp \

OBJS			= $(SRCS:.cpp=.o)

CC				= c++
CPPFLAGS	 	= -Wall -Wextra -Werror -std=c++98
RM				= rm -f

ORANGE			= \033[38;5;208m
RED				= \033[91m
RESET			= \033[0m

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "$(ORANGE)$@ $(MAGENTA)is perfectly compiled$(RESET)"

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)Boom Booom Boooom .o$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Boom Booom Boooom $(NAME)$(RESET)"

re: fclean all

run: $(NAME)
	@./$(NAME)

runv: $(NAME)
	@valgrind ./$(NAME)

.PHONY: all clean fclean re run runv
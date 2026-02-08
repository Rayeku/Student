# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 07:02:09 by abougrai          #+#    #+#              #
#    Updated: 2026/02/08 21:52:44 by rayeku           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=  Divide_and_conquer
SRCS			= 	main.cpp Account.cpp Bank.cpp \

OBJS			= $(SRCS:%.cpp=$(OBJDIR)/%.o)
HEADER			=	 Account.hpp Bank.hpp \

CC				= c++
CPPFLAGS	 	= -Wall -Wextra -Werror -std=c++98 -pedantic
RM				= rm -rf

OBJDIR 			= objects

ORANGE			= \033[38;5;208m
RED				= \033[91m
RESET			= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "$(ORANGE)$@ $(MAGENTA)is perfectly compiled$(RESET)"

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJDIR)
	@echo "$(RED)Boom Booom Boooom $(OBJDIR)$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Boom Booom Boooom $(NAME)$(RESET)"

re: fclean all

run: $(NAME)
	@./$(NAME) database

runv: $(NAME)
	@valgrind ./$(NAME) database

full: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) base

.PHONY: all clean fclean re run runv full
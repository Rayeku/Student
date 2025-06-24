# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 07:02:09 by abougrai          #+#    #+#              #
#    Updated: 2025/02/11 18:21:47 by rayeku           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=  RPN
SRCS			= 	main.cpp RPN.cpp \

OBJS			= $(SRCS:%.cpp=$(OBJDIR)/%.o)
HEADER			=	 RPN.hpp \

CC				= c++
CPPFLAGS	 	= -Wall -Wextra -Werror -std=c++98
RM				= rm -rf

OBJDIR 			= objects

ORANGE			= \033[38;5;208m
RED				= \033[91m
RESET			= \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "$(ORANGE)$@ $(MAGENTA)is perfectly compiled$(RESET)"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJDIR)
	@echo "$(RED)Boom Booom Boooom $(OBJDIR)$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Boom Booom Boooom $(NAME)$(RESET)"

re: fclean all

run: $(NAME)
	@./$(NAME) "1 2 * 4 - 2 + 5 * 2 +"

runv: $(NAME)
	@valgrind ./$(NAME) "1 2 * 4 - 2 + 5 * 2 +"

full: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) "1 2 * 4 - 2 + 5 * 2 +"

.PHONY: all clean fclean re run runv full
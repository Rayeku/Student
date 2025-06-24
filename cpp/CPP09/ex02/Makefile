# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 07:02:09 by abougrai          #+#    #+#              #
#    Updated: 2025/03/31 08:53:21 by rayeku           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=  	PmergeMe
SRCS			= 	 main.cpp PmergeMe.cpp \

OBJS			= $(SRCS:%.cpp=$(OBJDIR)/%.o)
HEADER			=	 PmergeMe.hpp \

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
	@./$(NAME) 0 91 7 271 4 213 482 432 492 49

runv: $(NAME)
	@valgrind ./$(NAME) 0 91 7 271 4 213 482 432 492 49

full: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 0 91 7 271 4 213 482 432 492 49

.PHONY: all clean fclean re run runv full
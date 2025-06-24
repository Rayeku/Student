# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 07:02:09 by abougrai          #+#    #+#              #
#    Updated: 2024/09/18 14:57:08 by abougrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME 			=  Polymorphism
SRCS			= 	main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp \

OBJS			= $(SRCS:%.cpp=$(OBJDIR)/%.o)
HEADER			=	Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp \

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
	@./$(NAME)

runv: $(NAME)
	@valgrind ./$(NAME)

full: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re run runv full
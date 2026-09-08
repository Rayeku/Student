# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 07:02:09 by abougrai          #+#    #+#              #
#    Updated: 2026/02/08 23:18:37 by rayeku           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			=  Solid
SRCS			= 	main.cpp \

OBJS			= $(SRCS:%.cpp=$(OBJDIR)/%.o)
HEADER			=	Car.hpp \

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
	@printf "$(ORANGE)$@ $(MAGENTA)is perfectly compiled$(RESET)\n"

$(OBJDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJDIR)
	@printf "$(RED)Boom Booom Boooom $(OBJDIR)$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)Boom Booom Boooom $(NAME)$(RESET)\n"

re: fclean all

run: $(NAME)
	@./$(NAME)

runv: $(NAME)
	@valgrind ./$(NAME)

full: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re run runv full
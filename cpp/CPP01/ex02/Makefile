# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefil                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/07 07:02:19 by abougrai          #+#    #+#              #
#    Updated: 2024/05/02 12:38:38 by abougrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= BRAIN
SRCS			= 	main.cpp \

OBJS			= $(SRCS:%.cpp=$(OBJDIR)/%.o)
HEADER			=	\

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

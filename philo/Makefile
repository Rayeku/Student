NAME 			= philo
SRCS			= 	main.c \
					./init/init_general.c \
					./init/init_thread.c \
					./init/init_time.c \
					./program/capart.c \
					./program/solo.c \
					./program/checker.c \
					./program/exit.c \
					./routine/print_r.c \
					./routine/eat.c \
					./routine/sleep.c \
					./routine/thinking.c \
					./handler/handler_death.c \
					./handler/handler_eat.c \
					./tools/tools.c \

OBJS			= $(SRCS:.c=.o)

CC				= cc
CFLAGS			= -Wall -Werror -Wextra 
RM				= rm -f

MAGENTA 		= \033[95m
ORANGE_FONCE	= \033[38;5;208m
ROUGE			= \033[91m
RESET			= \033[0m

# -fsanitize=thread
# -pthread -g3 -pthread

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(ORANGE_FONCE)$@ $(MAGENTA)is perfectly compiled$(RESET)"

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	@echo "$(ROUGE)Boom Booom Boooom .o$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(ROUGE)Boom Booom Boooom .a$(RESET)"

re: fclean all

run: $(NAME)
	@./$(NAME) 10 300 250 250 7 

runv: $(NAME)
	@valgrind --leak-check=full ./$(NAME) 10 600 15 15 4

full: $(NAME)
	@valgrind --leak-check=full --track-origins=yes ./$(NAME)  200 1200 200 200 15 

helgrind: $(NAME) 
	@valgrind --tool=helgrind  --history-level=approx ./$(NAME)  300 1200 200 200 15 

drd: $(NAME) 
	@valgrind --tool=helgrind --tool=drd ./$(NAME)   200 1200 200 200 15 

.PHONY: all clean fclean re exe exem exev exevm bonus helgrind drd
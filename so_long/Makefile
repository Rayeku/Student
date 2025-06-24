
CC = cc
#CFLAGS = -Wall -Wno-error -Wextra -I/usr/include -I./minilibx-linux -O3
CFLAGS = -Wall -Werror -Wextra -I/usr/include -I./minilibx-linux -O3
LDFLAGS = -L./minilibx-linux -L/usr/lib
LDLIBS = -lmlx_Linux -lXext -lX11 -lm -lz

LIBFT_SRCS = $(wildcard libft_r/*.c)
LIBFT_OBJS = ${LIBFT_SRCS:.c=.o}
SRCS = $(wildcard SRCS/*.c)
OBJS = ${SRCS:.c=.o}

NAME = so_long

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_OBJS)
	@cd minilibx-linux && $(MAKE)
	@$(CC) $(LDFLAGS) $(OBJS) $(LIBFT_OBJS) $(LDLIBS) -o $(NAME)
	@echo "\033[0;32mPerfect !\033[0m"

exe : $(NAME)
	@./so_long maptest.ber

exev : $(NAME)
	@valgrind ./$(NAME) maptest.ber

all: $(NAME)

clean:
	@rm -f ${OBJS} $(LIBFT_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re main exe

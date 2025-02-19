NAME = so_long
SRCS = main.c check.c image.c move.c put.c set.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Ilibft -Llibft -lft -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(OBJ) $(SRCS) $(CFLAGS)  -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
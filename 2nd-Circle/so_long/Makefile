NAME = so_long
SRCS = main.c check.c image.c move.c put.c set.c map_parse.c utils.c cpy_map.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft -Llibft -lft -Iprintf -Lprintf -lftprintf -Lmlx -lmlx -Imlx -framework AppKit -framework OpenGL

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -C printf
	$(CC) $(OBJ) $(SRCS) $(CFLAGS)  -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	@make fclean -C libft
	@make fclean -C printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
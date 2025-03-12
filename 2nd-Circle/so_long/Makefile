NAME = so_long
SRCS = main.c check.c image.c move.c put.c set.c map_parse.c utils.c cpy_map.c close.c check2.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
    MLX_DIR = mlx_opengl
    MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
    MLX_DIR = mlx
    MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
endif

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@make -C printf
	$(CC) $(OBJS) $(CFLAGS) -Ilibft -Iprintf $(MLX_FLAGS) -Llibft -lft -Lprintf -lftprintf -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Ilibft -Iprintf -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	@make fclean -C libft
	@make fclean -C printf
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re

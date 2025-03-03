NAME = so_long
SRCS = main.c check.c image.c move.c put.c set.c map_parse.c utils.c cpy_map.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Détection de l'OS
UNAME_S := $(shell uname -s)

# Définition des flags et dossiers MiniLibX en fonction de l'OS
ifeq ($(UNAME_S), Darwin)  # macOS
    MLX_DIR = mlx_opengl
    MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else  # Linux
    MLX_DIR = mlx
    MLX_FLAGS = -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
endif

# Compilation et création de l'exécutable
all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@make -C printf
	$(CC) $(OBJS) $(CFLAGS) -Ilibft -Iprintf $(MLX_FLAGS) -Llibft -lft -Lprintf -lftprintf -o $(NAME)

# Compilation des fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -Ilibft -Iprintf -I$(MLX_DIR) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJS)

# Nettoyage complet
fclean: clean
	@make fclean -C libft
	@make fclean -C printf
	rm -f $(NAME)

# Réinitialiser et recompiler
re: fclean all

.PHONY: all clean fclean re

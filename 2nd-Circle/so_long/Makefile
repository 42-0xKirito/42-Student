NAME = so_long
SRCS = main.c check.c image.c move.c put.c set.c map_parse.c utils.c cpy_map.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Compilation et création de l'exécutable
all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@make -C printf
	$(CC) $(OBJS) $(CFLAGS) -Ilibft -Iprintf -Imlx -Llibft -lft -Lprintf -lftprintf -Lmlx -lmlx -lXext -lX11 -lm -lz -o $(NAME)

# Compilation des fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -Ilibft -Iprintf -Imlx -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJS)

# Nettoyage complet
fclean: clean
	@make fclean -C libft
	@make fclean -C printf
	rm -f $(NAME)

# Réinitialiser et recompilation
re: fclean all

.PHONY: all clean fclean re

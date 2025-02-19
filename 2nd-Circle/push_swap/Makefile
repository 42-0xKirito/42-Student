NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = $(shell find ./cheapest ./commands ./free ./init ./parsing ./sorting ./utils -type f -name "*.c") main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

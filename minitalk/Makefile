SRCSClient	= client.c src/*.c
SRCSServer	= server.c src/*.c

CC			= cc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -f
OBJS		= $(SRCSClient:.c=.o) $(SRCSServer:.c=.o)

all:	
			$(CC) $(FLAGS) $(SRCSClient) -o client
			$(CC) $(FLAGS) $(SRCSServer) -o server


clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) client server

re:			fclean all

.PHONY:		all clean fclean re
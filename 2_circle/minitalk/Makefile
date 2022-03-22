.SUFFIXES : .c .o

SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

UTILS_O = utils.o
SERVER_O = server.o
CLIENT_O = client.o

UTILS_C = utils.c
SERVER_C = server.c
CLIENT_C = client.c

all : s c

s : $(SERVER)

c : $(CLIENT)

clean :
	$(RM) $(UTILS_O) $(CLIENT_O) $(SERVER_O)

fclean : clean
	$(RM) $(SERVER) $(CLIENT)

re : fclean all

.PHONY : all s c clean fclean re

$(SERVER) : $(UTILS_O) $(SERVER_O)
	$(CC) -o $@ $^

$(CLIENT) : $(UTILS_O) $(CLIENT_O)
	$(CC) -o $@ $^

.c.o :
	$(CC) $(CFALGS) -c $< -o $@
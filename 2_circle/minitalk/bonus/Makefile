.SUFFIXES : .c .o

SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all : s c

s : $(SERVER)

c : $(CLIENT)

clean :
	$(RM) utils_bonus.o server_bonus.o client_bonus.o

fclean : clean
	$(RM) $(SERVER) $(CLIENT)

re : fclean all

.PHONY : all s c clean fclean re

$(SERVER) : utils_bonus.o server_bonus.o
	$(CC) -o $@ $^

$(CLIENT) : utils_bonus.o client_bonus.o
	$(CC) -o $@ $^

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@
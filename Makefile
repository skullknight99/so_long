NAME = so_long

SRCS = so_long.c movement.c utils.c map.c gnl.c\
	utils1.c checkmap.c checkmap1.c countmove.c

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

FFLAGS = -lmlx -framework OpenGL -framework Appkit

CC = gcc

all: $(NAME)

$(NAME) : 
	$(CC) $(CFLAGS) $(FFLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

re: clean all
NAME = so_long

SRCS = so_long.c movement.c utils.c map.c gnl.c\
	utils1.c checkmap.c checkmap1.c countmove.c utils2.c\
	checkcomp.c

OBJS = ${SRCS:.c=.o}

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

FFLAGS = -lmlx -framework OpenGL -framework Appkit

CC = gcc

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(FFLAGS) $(SRCS) -o $(NAME)

clean:
	find . -name "*.o" -delete

fclean: clean
	$(RM) $(NAME)

re: fclean all
CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = philo

SRCS = philo.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $?

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean :


fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re

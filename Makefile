NAMEFILE = push_swap
NAME =	./*.c
CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJNAME = $(NAME:.c=.o)

all :
	$(CC) $(FLAGS) $(NAME) -o $(NAMEFILE)

clean:
	rm -rf $(OBJNAME)

fclean: clean
	rm -rf $(NAMEFILE)

norm:
	norminette *.[ch]

re:
	fclean all

.PHONY : re fclean clean all  norm


##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## true
##

NAME = bsq

SRC	=	bsq.c				\
		backslashnlen.c		\
		linelen.c			\
		makesquarre.c		\
		my_getnbr.c			\
		error.c 			\
		my_strlen.c 		\
		my_put_nbr.c 		\
		my_putchar.c		\
		create_map.c 		\
		print.c

CFLAGS = -W -Wextra -Wall

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc $(CFLAGS) -o $(NAME) $(SRC) -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test_clean :
	rm -f *.gcno
	rm -f *.gcda
	rm units_test

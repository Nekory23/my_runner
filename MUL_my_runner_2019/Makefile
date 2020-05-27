##
## EPITECH PROJECT, 2019
## my_runner
## File description:
## makefile
##

NAME	=	my_runner

SRC	=	src/main.c		\
		src/runner.c		\
		src/help_display.c	\
		src/error_handling.c	\
		util/my_putstr.c	\
		util/my_putchar.c	\
		util/my_strlen.c	\
		util/compare_str.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wextra -Wall

CPPFLAGS=	-I./include/

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lm

all	:	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(SRC) $(CPPFLAGS) $(LDFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

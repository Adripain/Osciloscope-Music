##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## 
##


NAME	= test

CC	= gcc

RM	= rm -f

SRC	= *.c

OBJ	= $(SRC:.c=.o)

LIBFLAG	= -L ./lib/my/ -lmy -lcsfml-graphics -lcsfml-system -lcsfml-window

LIBS = -lm

all: $(NAME)

$(NAME):
	cd lib/my && make re
	$(CC) $(SRC) -o $(NAME) $(LIBFLAG) $(LIBS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

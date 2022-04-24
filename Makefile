##
## EPITECH PROJECT, 2022
## my_ftp
## File description:
## Makefile
##

CC		= gcc

CFLAGS  = -W -Wall -Wextra

INCLUDE	= -I includes/

SRC		= main.c

SRC		+= $(wildcard src/*.c)
SRC		+= $(wildcard src/*/*.c)

OBJ		= $(SRC:.c=.o)

OUT		= my_ftp

all: $(OUT)

$(OUT): $(OBJ)
	gcc -o $@ $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(OUT)

re: fclean all

%.o : %.c
	$(CC) -c $< -o $@ $(INCLUDE) $(CFLAGS)
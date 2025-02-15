# -*- Makefile -*-

CC = cc

CFLAGS = -Werror -Wall -Wextra -g

NAME = pipex
LIBFTDIR = libft
LIBFT = libft/libft.a
SRC = pipex.c pipex_utils.c extra_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFTDIR) -I$(LIBFTDIR) -lft -o $(NAME)

# Add the -f flag to suppress errors
clean:
	rm -f *.o
	$(MAKE) clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re

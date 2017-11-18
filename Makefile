NAME = fillit
LIB = libft.a

FILENAMES = ft_get_id.c \
			ft_readfile.c \
			ft_tetradd.c \
			ft_tetrcheck.c \
			ft_tetrdel.c \
			ft_tetrnew.c \
			main.c \

SOURCES = $(addprefix ./src/, $(FILENAMES))
OBJECTS = $(addprefix obj/, $(FILENAMES:.c=.o))

CC = gcc
FLAGS ?= -Wall -Wextra -Werror
FLAGS += -I./includes/ -I./libft/

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB)
	$(CC) -o $@ $(FLAGS) $(OBJECTS) $(LIB)

$(LIB):
	make -C ./libft/

obj:
	mkdir obj/

obj/%.o: ./src/%.c | obj
	$(CC) -c $(FLAGS) $< -o $@

clean:
	make -C ./libft/ fclean
	rm -rf obj/

fclean: clean
	rm -f $(NAME)

re: fclean all

.NOTPARALLEL:
.PHONY: all clean fclean re

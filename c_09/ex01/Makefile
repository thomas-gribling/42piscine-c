LIB_NAME = libft.a

SOURCE_FILES = ft_putchar.c \
				ft_swap.c \
				ft_putstr.c \
				ft_strlen.c \
				ft_strcmp.c

OBJECT_FILES = $(SOURCE_FILES:.c=.o)

all: $(LIB_NAME)

$(LIB_NAME):
	gcc -Wall -Wextra -Werror -c $(addprefix srcs/, $(SOURCE_FILES)) -I includes
	mv $(OBJECT_FILES) srcs/
	ar -rc $@ $(addprefix srcs/, $(OBJECT_FILES))

clean:
	rm -rf $(addprefix srcs/, $(OBJECT_FILES))

fclean: clean
	rm -rf $(LIB_NAME)

re: fclean all

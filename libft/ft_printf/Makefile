NAME = libftprintf.a
CC = CC
CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./ft_printf.h

CFILES = \
		./ft_printf.c \
		./ft_put_unsigned_nbr.c \
		./ft_putchar.c \
		./ft_putnbr.c \
		./ft_putp.c \
		./ft_putstr.c \
		./ft_putx.c \
		./ft_putxxx.c 
		
OBJECTS = $(CFILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDES)
		ar rcs $(NAME) $(OBJECTS)

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $<

clean:
		rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re

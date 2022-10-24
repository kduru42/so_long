NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SOURCE = ft_print_percent.c ft_print_unsigned.c ft_printchar.c ft_printf.c ft_printhex_lower.c ft_printhex_upper.c ft_printnbr.c ft_printptr.c ft_printstring.c

OBJECT = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	ar rcs $(NAME) $(OBJECT)

comp:
	gcc ft_printf.c libftprintf.a

clean:
	$(RM) $(OBJECT)

fclean: clean
	$(RM) $(NAME)
	@echo "All Deleted..."

re: fclean all

.PHONY: clean fclean all re
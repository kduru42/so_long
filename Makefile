NAME = so_long
CC = gcc -g
FLAGS = -Werror -Wextra -Wall
RM = rm -rf

MAIN = main.o

SOURCE = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c ./src/create_map.c ./src/so_long_utils.c ./src/get_counts.c \
		./src/check_rectangular.c ./src/split_map.c ./src/check_valid.c ./src/init_data.c ./img_src/put_xpm.c ./img_src/key_events.c ./img_src/key_checkers.c

OBJECT= $(SOURCE:%.c.=%.o)

all: $(NAME)

$(NAME): $(MAIN) $(OBJECT)
	@make -C ./ft_printf
	@make -C ./mlx
	$(CC) $(FLAGS) $(OBJECT) -framework OpenGL -framework AppKit mlx/libmlx.a ./ft_printf/libftprintf.a $(MAIN) -o $(NAME) -ggdb
	
clean:
	$(RM) src/*.o ft_printf/*.o get_next_line/*.o $(MAIN)
	@make -C ./ft_printf fclean

fclean: clean
	$(RM) $(NAME)
	@make -C ./mlx clean

re: fclean all

.PHONY: all clean fclean re
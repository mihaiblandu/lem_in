NAME = lem_in.out

FLAGS = -Wall -Wextra -Werror

SRC = main.c ant_number.c get_rooms.c get_links.c create_tree.c

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft/
			@gcc $(FLAGS) -o $@ $(SRC) libft/libft.a
				@rm -r $(OBJ)

%.o: %.c
		@gcc $(FLAGS) -I libft/includes -c -o $@ $<

clean:
		@rm -f $(OBJ)

fclean: clean
		@make fclean -C ./libft
			@rm -f $(OBJ) $(NAME)

re: fclean all

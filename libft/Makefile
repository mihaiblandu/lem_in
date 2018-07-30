NAME = libft.a
FLAGS =
HEADER = includes/
SRC = ft_mem/ft_memset.c ft_str/ft_bzero.c ft_mem/ft_memcpy.c ft_mem/ft_memccpy.c ft_mem/ft_memmove.c \
		  ft_mem/ft_memchr.c ft_mem/ft_memcmp.c ft_str/ft_strlen.c ft_str/ft_strdup.c ft_str/ft_strcpy.c \
		  ft_str/ft_strncpy.c ft_str/ft_strcat.c ft_str/ft_strncat.c ft_str/ft_strlcat.c ft_str/ft_strchr.c \
		  ft_str/ft_strrchr.c ft_str/ft_strstr.c ft_str/ft_strnstr.c ft_str/ft_strcmp.c ft_str/ft_strncmp.c \
		  ft_to/ft_atoi.c ft_is/ft_isalpha.c ft_is/ft_isdigit.c ft_is/ft_isalnum.c ft_is/ft_isascii.c \
		  ft_is/ft_isprint.c ft_to/ft_toupper.c ft_to/ft_tolower.c ft_mem/ft_memalloc.c ft_mem/ft_memdel.c \
		  ft_str/ft_strnew.c ft_str/ft_strdel.c ft_str/ft_strclr.c ft_str/ft_striter.c ft_str/ft_striteri.c \
		  ft_str/ft_strmap.c ft_str/ft_strmapi.c ft_str/ft_strequ.c ft_str/ft_strnequ.c ft_str/ft_strsub.c \
		  ft_str/ft_strjoin.c ft_str/ft_strtrim.c ft_str/ft_strsplit.c ft_to/ft_itoa.c ft_put/ft_putchar.c \
		  ft_put/ft_putstr.c ft_put/ft_putendl.c ft_put/ft_putnbr.c ft_put/ft_putchar_fd.c ft_put/ft_putstr_fd.c \
		  ft_put/ft_putendl_fd.c ft_put/ft_putnbr_fd.c  ft_lst/ft_lstnew.c ft_lst/ft_lstdelone.c \
		  ft_lst/ft_lstdel.c ft_lst/ft_lstadd.c ft_lst/ft_lstiter.c ft_lst/ft_lstmap.c ft_str/ft_strrev.c \
		  ft_lst/ft_list_size.c ft_to/ft_uppercase.c ft_to/ft_lowercase.c ft_str/ft_sort.c ft_is/ft_max.c

SRC_PRINTF = ft_printf/ft_printf.c ft_printf/parse_conversion.c ft_printf/ft_itoa_base.c ft_printf/concat.c ft_printf/ft1.c ft_printf/ft2.c ft_printf/wchar.c \
			 		ft_printf/print_integer.c ft_printf/print_string.c ft_printf/print_char.c ft_printf/print_float.c ft_printf/get_float.c \
							ft_printf/print_float_e.c ft_printf/print_float_g.c ft_printf/print_float_hex.c ft_printf/print_bonus.c ft_printf/print_color.c

GNL_SRC = get_next_line/get_next_line.c

ALL_SRC = $(SRC) $(SRC_PRINTF) $(GNL_SRC)

OBJ = $(ALL_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@rm -r $(OBJ)

%.o: %.c
	@gcc $(FLAGS) -I $(HEADER) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

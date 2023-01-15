##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC 	=   my/utils/my_putchar.c \
		my/utils/is_float.c \
		my/utils/my_put_nbr.c \
		my/utils/my_putstr.c \
		my/utils/my_revstr.c \
		my/utils/my_strcat.c \
		my/utils/my_strcpy.c \
		my/utils/my_str_isalpha.c \
		my/utils/my_strlen.c \
		my/utils/my_strncat.c \
		my/utils/my_int_to_str.c \
		my/utils/my_long_to_str.c \
		my/utils/my_strdup.c \
		my/utils/my_uint_to_str.c \
		my/utils/my_ulong_long_to_str.c \
		my/utils/is_only_num.c \
		my/utils/is_num.c \
		my/utils/str_split.c \
		my/utils/my_strcmp.c \
		my/src/flags/handle_l.c \
		my/utils/check_if_file.c \
		my/src/flags/handle_a.c \
		my/src/flags/handle_d.c \
		my/utils/print_file_path.c \
		my/utils/calls_read_directory.c \
		my/utils/initiate_ship.c \
		my/utils/initiate_bg.c \
		my/utils/destructor.c \
		my/utils/init_window.c \
		my/utils/init_meteorit.c \
		my/utils/-h.c \
		my/utils/change_ship.c \
		my/utils/change_shipv2 \
		my/utils/init_objects.c \
		my/utils/string_to_float.c \
		my/utils/my_memcpy.c \
		my/utils/my_getnbr.c \
		my/utils/display_usage.c

NAME	=	libmy.a

OBJ	=	 $(SRC:.c=.o)

CFLAGS = -I./my/utils -g3

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all

##
## EPITECH WORKSHOP, 2022
## Makefile
## File description:
## Root makefile
##

SRC 	=   $(wildcard *.c)\
			$(wildcard ./system/*.c)\
			$(wildcard ./system/clock/*.c)\
			$(wildcard ./system/game/*.c)\
		  	$(wildcard ./system/game/events/*.c)\
		  	$(wildcard ./system/game/scene/*.c)\
		  	$(wildcard ./system/game/window/*.c)\
			$(wildcard ./lib/my/utils/*.c) \
			$(wildcard ./ObjectecOrientedProgramming/*.c) \
			$(wildcard ./system/game/info/*.c) \
			$(wildcard ./system/props/airplane/*.c) \
			$(wildcard ./system/props/tower/*.c)

OBJ 			= 		$(SRC:.c=.o)

NAME 			=		my_radar

CFLAGS 			= 		 -Wextra -Wshadow -W -Wall -I./include/ #-Werror

CSFML_FLAGS 	=		-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm


#
# For MacOS, use CSFML from local files ( ./__OSX__ ) // Otherwise ignore
OS_NAME 		=		$(shell uname -s | tr A-Z a-z)

ifeq ($(OS_NAME), darwin)
	CSFML_LIB = -L./__OSX__/lib
	CFLAGS += -I./__OSX__/include
endif
#
#

all: $(NAME)

$(NAME): 		$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CSFML_LIB) $(CSFML_FLAGS)

clean:
		$(RM) -f $(OBJ)
		$(RM) src/*.o

fclean:		clean
		$(RM) $(NAME)

re: 	fclean all

test:
		make -C tests/

.PHONY  : all clean fclean re test

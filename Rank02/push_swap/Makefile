#Program name
NAME = push_swap

#libft directory path
LIBFT_PATH = ./libft/

LIBFT = libft

LIBFT.A = libft.a

#ft_printf directory path

FTPRINTF.A = ./libft/ft_printf/libftprintf.a

#includes path

I = ./includes/

# Source files for push_swap
SRC = push_swap.c $(wildcard ${I}*.c)

# Compilation instructions
CFLAGS = -Wall -Wextra -Werror
CC = cc -g -o push_swap.out
AR = ar -rcs
RM = rm -f

#Address Sanitizer
SANITIZE = -fsanitize=address -static-libsan

# -C option for make changes directory and search in /libft

all:	${NAME}

$(LIBFT.A) :
	@make -C $(LIBFT)
	@echo "libft functions compiled!"

$(NAME) :	${SRC} ${LIBFT.A}
	${CC} ${SRC} ${LIBFT_PATH}${LIBFT.A} ${FTPRINTF.A}

#Clean norm to delete all OBJECTS (o.files)
clean:	
	${RM} *.out
	@make clean -C $(LIBFT)
	@echo "*.o cleaned!"

#fclean to delete all (.a files and NAME)
fclean:	clean
#	${RM} ${NAME}
	@make fclean -C $(LIBFT)
	@echo "*.o and *.a cleaned!"

#re to remake, it is similar to execute make for the first time
re:	fclean all
	@echo "all cleaned and rebuilt!"

.PHONY: all clean fclean bonus re
#Library name
NAME = libftprintf.a

#Source Files
SRC 		= 	ft_print_char.c ft_print_str.c ft_print_decimal_int.c \
				ft_print_memory.c ft_print_unsigned.c ft_print_hex_lower.c \
				ft_print_hex_upper.c ft_printf.c \

# Transform .c to .o
OBJ 		= 	${SRC:.c=.o}

#Compile with flags
RM		=	rm -f
CC		=	cc -c
CFLAGS	=	-Wall -Wextra -Werror


#Compile the binary exe
all:	${NAME}

#Compile each object
$(NAME) : 	${OBJ}
	ar -rcs ${NAME} ${OBJ}

#Clean norm to delete all OBJECTS (.o files)
clean:	
		${RM} ${OBJ}

#fclean to delete all (.a files and NAME)
fclean:	clean 
		${RM} ${NAME}

#re to remake it is similar to execute make for the first time
re:	fclean all

#PHONY lets make know that all, clean, fclean and re are not files
.PHONY: all clean fclean re
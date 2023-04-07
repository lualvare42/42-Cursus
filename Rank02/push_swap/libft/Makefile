#Program name
NAME = libft.a

#ft_printf directory path
FTPRINTF_PATH = ./ft_printf/

FTPRINTF = ft_printf

FTPRINTF.A = libftprintf.a

#circular lists functions directory path
CHL_PATH = ./ch_list/

#Source Files
SRC 		= 	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isalnum.c \
				ft_strlen.c ft_isprint.c ft_tolower.c ft_toupper.c ft_strncmp.c \
				ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_strchr.c ft_strrchr.c \
				ft_memchr.c ft_memcmp.c ft_memcpy.c ft_bzero.c ft_memmove.c \
				ft_memset.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_itoa.c ft_strmapi.c ft_striteri.c\
				ft_isspace.c ft_sign.c ft_int.c ft_digitdup_check.c ft_int_check.c ft_isint.c ft_atoi_index.c \
				ft_dup_inarray.c ft_latoi_index.c ft_abs.c ft_abs_greater.c ft_abs_less.c 

CHL			=	$(wildcard ${CHL_PATH}*.c)

SRC_BONUS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c ft_lstiter_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
				ft_lstmap_bonus.c \

# Transform .c to .o
OBJ 		= 	${SRC:.c=.o}
OBJ_CHL		=	${CHL:.c=.o}
OBJ_BONUS 	= 	${SRC_BONUS:.c=.o}

#Compile with flags
RM		=	rm -f
CC		=	cc -c
CFLAGS	=	-Wall -Wextra -Werror


#Compile the binary exe
all:	${NAME}

#Compile ft_printf
$(FTPRINTF.A) :
	@make -C $(FTPRINTF)
	@echo "ftprintf functions compiled!"

#Compile each object
$(NAME) : 	${OBJ} ${OBJ_CHL} ${FTPRINTF.A}
	ar -rcs ${NAME} ${OBJ} ${OBJ_CHL} ${FTPRINTF_PATH}${FTPRINTF.A}

#Clean norm to delete all OBJECTS (.o files)
clean:	
		${RM} ${OBJ} ${OBJ_BONUS} ${OBJ_CHL}
		@make clean -C $(FTPRINTF)

#fclean to delete all (.a files and NAME)
fclean:	clean 
		${RM} ${NAME}
		@make fclean -C $(FTPRINTF)

#Compile each bonus
bonus:	
		${CC} ${CFLAGS} ${SRC_BONUS}
		ar -rcs ${NAME} ${OBJ_BONUS}

#re to remake it is similar to execute make for the first time
re:	fclean all

#PHONY lets make know that all, clean, fclean and re are not files
.PHONY: all clean fclean re
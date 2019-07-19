##
## EPITECH PROJECT, 2018
## 102architect_2018
## File description:
## Makefile
##

NAME	=	103cipher
SRC	=	$(wildcard src/*.c)
OBJ	=	$(SRC:.c=.o)

SRC_BONUS	=	$(wildcard bonus/*.c)
OBJ_BONUS	=	$(SRC_BONUS:.c=.o)

CFLAGS += -Iinclude/

LIB	= -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LIB)

bonus:	$(OBJ_BONUS)
	@gcc -o $(NAME)_bonus $(OBJ_BONUS) $(LIB)

tests_run:
	gcc tests/*.c src/check_errors.c src/compt_int_len.c src/create_key.c src/create_matrix.c src/decrypt.c src/determinant.c src/encrypt.c src/my_getnbr.c src/my_int_getnbr.c src/reverse_matrix.c src/utils_sec.c src/utils.c -Iinclude -lcriterion --coverage -lm
	@./a.out
	@gcovr --branches --exclude tests
	@rm -f a.out

asm:
	@gcc -S $(SOURCES) $(LIB)

clean:
	@find . -name \*.o -type f -delete
	@find . -name \*.gc\* -type f -delete

fclean:	clean
	@rm -f $(NAME)
	@rm -f *.s

re:	fclean	$(NAME)

.PHONY:	all	$(NAME)	clean	fclean	re	bonus	tests_run
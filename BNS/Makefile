CC=gcc
NAME=checker
CFLAGS=-Wall -Wextra -Werror
LIB_DIR=../libft/
LIB=libft.a
LIB_INC=libft.h
INC = INC/push_swap.h

SRC =	SRC/moves1.c		\
		SRC/moves2.c		\
		SRC/checker.c		\
		SRC/stack1.c		\
		SRC/stack2.c		\
		SRC/parse.c
		

OBJ=$(SRC:.c=.o)

all:
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) $(NAME)

%.o: %.c $(INC) 
	@echo "Compilant $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIB_DIR)$(LIB) $(OBJ) 
	@echo "Enllaçant $@"
	@$(CC) $(CFLAGS) $(LIB_DIR)$(LIB) $(OBJ) $< -o $(NAME)

clean:
	rm -f $(OBJ) $(OBJ_BNS)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all re
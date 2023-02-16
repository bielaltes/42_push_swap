CC=gcc
NAME=push_swap
CFLAGS=-Wall -Wextra -Werror
LIB_DIR=libft/
LIB=libft.a
LIB_INC=libft.h
INC = INC/push_swap.h

SRC =	SRC/moves1.c		\
		SRC/moves2.c		\
		SRC/parse.c			\
		SRC/push_swap.c		\
		SRC/stack1.c			\
		SRC/stack2.c			\
		SRC/algorithm.c		\
		SRC/fast_sort.c
		
BNS_DIR = BNS/
BNS_NAME = checker

OBJ=$(SRC:.c=.o)

OBJ_BNS=$(SRC_BNS:.c=.o)

all:
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) $(NAME)

%.o: %.c $(INC) 
	@echo "Compilant $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIB_DIR)$(LIB) $(OBJ) 
	@echo "Enllaçant $@"
	@$(CC) $(CFLAGS) $(LIB_DIR)$(LIB) $(OBJ) $< -o $(NAME)

bonus:
	@$(MAKE) -C $(BNS_DIR)
	@cp $(BNS_DIR)$(BNS_NAME) .

clean:
	rm -f $(OBJ) $(OBJ_BNS)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all re bonus
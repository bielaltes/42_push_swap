CC=gcc
NAME=push_swap
CFLAGS=-Wall -Wextra -Werror -g
LIB_DIR=libft/
LIB=libft.a
LIB_INC=libft.h
INC = INC/push_swap.h

SRC =	SRC/moves1.c		\
		SRC/parse.c			\
		SRC/push_swap.c		\
		SRC/stack.c			\
		SRC/algorithm.c		\
		SRC/fast_sort.c
		
SRC_BNS = SRC_bonus/checker.c

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
	@$(CC) $(CFLAGS) $(LIB_DIR)$(LIB) $(SRC_BNS) -o checker_biel

clean:
	rm -f $(OBJ) $(OBJ_BNS)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all re bonus
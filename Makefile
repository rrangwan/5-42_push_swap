NAME = push_swap

SRCS =	long.c main.c parser.c parser2.c short.c utils.c ./bonus/utils3.c utils2.c rank.c ops1.c ops2.c ops3.c utils4.c ft_split.c longer.c

BONUS = ./bonus/bonus.c ./bonus/gnl.c ./bonus/ops1_b.c ./bonus/ops2_b.c ./bonus/ops3_b.c ./bonus/utils3.c \
		long.c parser.c parser2.c short.c utils.c utils2.c rank.c ops1.c ops2.c ops3.c utils4.c ft_split.c longer.c

CC = @gcc

OBJS = $(SRCS:.c=.o)

BONUS_OBJ = $(BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g3

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o checker

clean:
	@rm -rf $(OBJS)
	@rm -rf $(BONUS_OBJ)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf checker

re: fclean all

.PHONY: clean fclean re bonus all

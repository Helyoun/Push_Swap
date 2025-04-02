CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror

SRC	=	main.c	\
		parsing/ft_get_middle.c	parsing/ft_get_target.c	parsing/ft_make_lis1.c	parsing/ft_make_lis.c	parsing/ft_parsing1.c	parsing/ft_parsing.c \
		checker_manda/ft_check_lis.c	checker_manda/ft_check_stack.c	\
		algorithme/algo.c	algorithme/ft_do_moves.c	\
		operations/ABS.c	operations/ft_move_to_top.c	operations/push.c	operations/reverse_rotate.c	operations/rotate.c	operations/swap.c

BNS	=	bonus/check_stack/ft_check_moves.c	bonus/operations/push.c	bonus/check_stack/ft_check_stack.c	bonus/operations/reverse_rotate.c \
		bonus/libft/ft_strcmp.c	bonus/operations/rotate.c	bonus/libft/get_next_line.c	bonus/libft/get_next_line_utils.c	bonus/operations/swap.c	\
       		bonus/parsing/ft_parsing1.c	bonus/main.c	bonus/parsing/ft_parsing.c

BNAME	=	checker

NAME	=	push_swap

OSRC	=	$(SRC:.c=.o)

OBNS	=	$(BNS:.c=.o)

all :	$(NAME)


$(NAME)	:	$(OSRC)
	$(CC) $(CFLAGS) $(OSRC) -o $(NAME) #-g3 -fsanitize=Address

bonus	:	$(BNAME)


$(BNAME):	$(OBNS)
	$(CC) $(CFLAGS) $(OBNS) -o $(BNAME)

clean:
	rm -f $(OSRC) $(OBNS)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: clean

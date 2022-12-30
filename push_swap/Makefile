# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: itopchu <itopchu@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/18 15:16:33 by itopchu       #+#    #+#                  #
#    Updated: 2022/12/18 15:16:33 by itopchu       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

EXEC	= push_swap
CC		= gcc
#******************************************************************************#
INC		= include/
LIBFT	= include/libft
PRINTF	= include/printf
#******************************************************************************#
SRC_DIR	= ./src/
SRC		= $(addprefix $(SRC_DIR), $(SRC_F))
SRC_F	=	actions.c \
			check_2.c \
			check.c \
			helper.c \
			list_utils.c \
			main.c \
			push_swap.c \
			table_init.c


OBJ		= ${SRC:.c=.o}
#******************************************************************************#
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -f
#******************************************************************************#
%.o: %.c
	$(CC) $(CFLAGS) -c $< -I $(INC) -I $(LIBFT) -I $(PRINTF) -o $@

$(EXEC): $(OBJ)
	$(MAKE) bonus -C $(LIBFT)
	$(MAKE) -C $(PRINTF)
	$(CC) -o $(EXEC) $(CFLAGS) $(OBJ) $(LIBFT)/libft.a $(PRINTF)/libftprintf.a
#******************************************************************************#
all		: $(EXEC)

debug	: CFLAGS = -g -fsanitize=address
debug	: fclean all

clean	:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(PRINTF) clean
	$(RM) $(OBJ)

fclean	: clean
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(PRINTF) fclean
	$(RM) $(EXEC)

re		: fclean all

.PHONY	: all, clean, fclean, re

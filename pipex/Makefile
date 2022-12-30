# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: itopchu <itopchu@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/30 02:36:30 by itopchu       #+#    #+#                  #
#    Updated: 2022/12/30 02:36:30 by itopchu       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

EXEC	= pipex
CC		= gcc
#******************************************************************************#
INC		= inc/
LIBFT	= inc/libft
PRINTF	= inc/printf
#******************************************************************************#
SRC_DIR	= ./src/
SRC		= $(addprefix $(SRC_DIR), $(SRC_F))
SRC_F	=	pipex.c \
			main.c

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
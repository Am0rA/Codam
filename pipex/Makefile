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
#******************************************************************************#
INC		= inc/
LIBFT	= inc/libft
PRINTF	= inc/printf
GET_LIN = inc/get_next_line
#******************************************************************************#
SRC_DIR	= ./src/
SRC		= $(addprefix $(SRC_DIR), $(SRC_F))
SRC_F	=	main.c \
			pipex.c \
			utils.c

OBJ		= ${SRC:.c=.o}
#******************************************************************************#
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
COMPILE = $(CC) $(CFLAGS)
RM		= rm -f
#******************************************************************************#
%.o: %.c $(HEADER)
	$(COMPILE) -c $< -I $(INC) -I $(LIBFT) -I $(PRINTF) -I $(GET_LIN) -o $@

$(EXEC): $(OBJ)
	$(MAKE) -C $(PRINTF)
	$(MAKE) -C $(GET_LIN)
	$(MAKE) bonus -C $(LIBFT)
	$(CC) -o $(EXEC) $(CFLAGS) $(OBJ) $(LIBFT)/libft.a $(PRINTF)/libftprintf.a $(GET_LIN)/get_next_line.a
#******************************************************************************#
all		: $(EXEC)

debug	: CFLAGS = -g -fsanitize=address
debug	: fclean all

clean	:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(PRINTF) clean
	$(MAKE) -C $(GET_LIN) clean
	$(RM) $(OBJ)

fclean	: clean
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(PRINTF) fclean
	$(MAKE) -C $(GET_LIN) fclean
	$(RM) $(EXEC)

re		: fclean all

.PHONY	: all, clean, fclean, re
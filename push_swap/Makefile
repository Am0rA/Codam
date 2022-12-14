# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: itopchu <itopchu@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/27 21:07:01 by itopchu       #+#    #+#                  #
#    Updated: 2022/11/27 21:07:01 by itopchu       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap.a
HEADER	= push_swap.h
####################################
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS)
RM		= rm -rf
####################################
AR		= ar
ARFLAGS	= -rcs
ARCHIVE	= $(AR) $(ARFLAGS)
####################################
SRC 	=	actions.c \
			check.c \
			error.c \
			list_actions.c \
			main.c \
			next_s-b.c \
			path_finder.c \
			push_swap.c \
			table.c
OBJ		= $(SRC:.c=.o)
OBJL	= libft/*.o
OBJP	= printf/*.o
####################################
all: $(NAME)($(OBJ))
	$(MAKE) -C libft/
	$(MAKE) -C printf/

%.o: %.c $(HEADER)
	$(COMPILE) -c $< -o $@

$(NAME): $(OBJ)
	$(ARCHIVE) $(NAME) $< $(OBJL) $(OBJP)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C libft/ clean
	$(MAKE) -C printf/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft/ fclean
	$(MAKE) -C printf/ fclean
	

re: fclean all

.PHONY: clean all fclean re

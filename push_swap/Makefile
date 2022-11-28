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
SRC 	=	push_swap.c \
			error.c \
			actions.c
OBJ		= $(SRC:.c=.o)
OBJL	= libft/*.o
####################################
all: $(NAME)($(OBJ))
	cd libft && $(MAKE)

%.o: %.c $(HEADER)
	$(COMPILE) -c $< -o $@

$(NAME): $(OBJ)
	$(ARCHIVE) $(NAME) $< $(OBJL)

clean:
	$(RM) $(OBJ)
	cd libft && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	cd libft && $(MAKE) fclean

re: fclean all

.PHONY: clean all fclean re

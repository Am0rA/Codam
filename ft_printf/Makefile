# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: itopchu <itopchu@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/23 00:59:22 by itopchu       #+#    #+#                  #
#    Updated: 2022/10/23 00:59:22 by itopchu       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
HEADER	= ft_printf.h
####################################
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS)
RM		= rm -r
####################################
AR		= ar
ARFLAGS	= -rcs
ARCHIVE	= $(AR) $(ARFLAGS)
####################################
SRC 	=	ft_printf.c \
			write.c \
			hex.c \
			based_int.c \
			base_conv.c

OBJ		= $(SRC:.c=.o)
####################################
all: $(NAME)

$(NAME): $(OBJ)
	$(ARCHIVE) $(NAME) $<

$(OBJ): $(SRC)
	$(COMPILE) -c $<

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean
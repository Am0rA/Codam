# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: itopchu <itopchu@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/23 00:59:22 by itopchu       #+#    #+#                  #
#    Updated: 2022/11/16 15:09:34 by itopchu       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
HEADER	= ft_printf.h
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
SRC 	=	ft_printf.c \
			write.c \
			hex.c \
			based_int.c \
			base_conv.c

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

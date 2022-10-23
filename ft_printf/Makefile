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

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS)

AR		= ar
ARFLAGS	= -rc
ARCHIVE	= $(AR) $(ARFLAGS)

RM		= rm -r

SRC 	=	ft_printf.c \
			ft_parse.c
SRC_B	= 

OBJ		= $(SRC:.c=.o)
OBJ_B	= $(SRC_B:.c=.o)

ifdef WITH_BONUS
SRC += $(SRC_B)
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(ARCHIVE) $(NAME) $<

$(OBJ): $(SRC)
	$(COMPILE) -c $<

bonus:
	$(MAKE) WITH_BONUS=1

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re fclean clean
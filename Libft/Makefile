# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: itopchu <itopchu@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/10 12:33:37 by itopchu       #+#    #+#                  #
#    Updated: 2022/10/10 18:56:58 by itopchu       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc
CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC=ft_atoi.c ft_bzero.c ft_calloc.c ft_split.c \
	ft_substr.c ft_is*.c ft_mem*.c ft_put*.c \
	ft_str*.c ft_to*.c
OBJ=*.o

SRCB= ft_l*.c
OBJB=$(BONUS:.c=.o) 

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c -I $(SRC)

clean:
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME)

re: fclean all	

bonus : $(OBJB) $(OBJB)
	ar rcs $(NAME) $(OBJ) $(OBJB)

.PHONY: clean fclean all re bonus
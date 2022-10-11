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

SRC=ft_*.c
OBJ=*.o

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c -I $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all	

.PHONY: clean fclean all re
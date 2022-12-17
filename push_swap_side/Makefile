# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: itopchu <itopchu@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/17 15:14:18 by itopchu       #+#    #+#                  #
#    Updated: 2022/12/17 15:14:18 by itopchu       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
HEADER	= push_swap.h
####################################
CFLAGS	= -Wall -Wextra -Werror -g
COMPILE = $(CC) $(CFLAGS)
RM		= rm -rf
####################################
AR		= ar
ARFLAGS	= -rcs
ARCHIVE	= $(AR) $(ARFLAGS)
####################################
LIBFT	= include/libft/libft.a
PRINTF	= include/printf/libftprintf.a
####################################
OBJ_D	=	obj
SRC 	=	source_files/main.c \
			source_files/check.c \
			source_files/clean.c \
			source_files/error.c \
			source_files/next_biggest.c \
			source_files/next_smallest.c \
			source_files/path_assign.c \
			source_files/path_put.c \
			source_files/path_utils.c \
			source_files/push.c \
			source_files/reverse_rotate.c \
			source_files/rotate.c \
			source_files/sorted.c \
			source_files/swap.c \
			source_files/table_init.c \
			source_files/utils.c
OBJ		= $(addprefix $(OBJ_D)/, $(notdir $(SRC:.c=.o)))
####################################

all: $(NAME)

debug: CFLAGS = -g -fsanitize=address
debug: fclean all

$(NAME): $(LIBFT) $(PRINTF) $(OBJ)
	$(COMPILE) $^ -I $(dir $(LIBFT)) -I $(dir $(PRINTF)) -I . -o $@

$(OBJ_D)/%.o: source_files/%.c
	$(COMPILE) -I. -c $< -o $@

$(OBJ_D):
	mkdir -p $(OBJ_D)

$(OBJ): $(SRC) | $(OBJ_D)

$(PRINTF):
	$(MAKE) -C ./include/printf

$(LIBFT):
	$(MAKE) -C ./include/libft

clean:
	@$(MAKE) -C include/libft/ clean
	@$(MAKE) -C include/printf/ clean
	$(RM) $(OBJ_D)

fclean: clean
	@$(MAKE) -C include/libft/ fclean
	@$(MAKE) -C include/printf/ fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean all fclean re

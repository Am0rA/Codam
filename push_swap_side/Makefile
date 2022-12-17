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
SRC 	=	main.c \

OBJ		= $(SRC:.c=.o)
OBJL	= include/libft/*.o
OBJP	= include/printf/*.o
####################################
all: $(NAME)($(OBJ))
	$(MAKE) -C include/libft/
	$(MAKE) -C include/printf/

%.o: %.c $(HEADER)
	$(COMPILE) -c $< -o $@

$(NAME): $(OBJ)
	$(ARCHIVE) $(NAME) $< $(OBJL) $(OBJP)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C include/libft/ clean
	$(MAKE) -C include/printf/ clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C include/libft/ fclean
	$(MAKE) -C include/printf/ fclean

re: fclean all

.PHONY: clean all fclean re

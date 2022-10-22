# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: itopchu <itopchu@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/10 12:33:37 by itopchu       #+#    #+#                  #
#    Updated: 2022/10/22 15:26:59 by itopchu       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
HEADER	= libft.h

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS)

RM		= rm -f

AR		= ar
ARFLAGS	= -rc
ARCHIVE	= $(AR) $(ARFLAGS)

SRC 	=	ft_atoi.c \
			ft_bzero.c \
			ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_split.c 

SRCB	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

OBJ		= $(SRC:.c=.o)
OBJB	= $(SRCB:.c=.o)

ifdef WITH_BONUS
SRC += $(SRCB)
endif

all: $(NAME)($(OBJ))

bonus:
	$(MAKE) WITH_BONUS=1

%.o: %.c $(HEADER)
	$(COMPILE) -c $< -o $@ 

$(NAME): $(OBJ)
	$(ARCHIVE) $(NAME) $<

clean:
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean all fclean re bonus
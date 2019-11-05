# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jlensing <jlensing@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 12:23:24 by jlensing       #+#    #+#                 #
#    Updated: 2019/11/05 19:47:39 by jlensing      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft

SRC_MAP = srcs/

SRC_FILES = ft_strlen.c ft_atoi.c ft_tolower.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_strncmp.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strchr.c ft_strlcpy.c ft_strlcat.c ft_strrchr.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_strjoin.c ft_substr.c ft_split.c

SRC = $(addprefix $(SRC_MAP), $(SRC_FILES))

BONUS = ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstclear_bonus.c

BONUS_SRC = $(addprefix $(SRC_MAP), $(BONUS))


GCC = gcc -c $(SRC) $(BONUS_SRC) -Wall -Werror -Wextra 
GCC_BONUS = gcc -c $(SRC) $(BONUS_SRC) -Wall -Werror -Wextra 
ARRC = ar rc libft.a ft_*.o

$(NAME): all

all: 
	$(GCC)
	$(ARRC)
	rm -f *.o
	
clean:
	rm -f *.o

fclean: clean
	rm -f *.o
	rm -f $(NAME).a

re: fclean all

bonus:
	$(GCC_BONUS)
	rm -f *.o
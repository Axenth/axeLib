# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jlensing <jlensing@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 12:23:24 by jlensing       #+#    #+#                 #
#    Updated: 2019/11/02 18:06:12 by jlensing      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft

SRC_MAP = srcs/

SRC_FILES = ft_strlen.c ft_atoi.c ft_tolower.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_strncmp.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strchr.c ft_strlcpy.c ft_strlcat.c ft_strrchr.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_strjoin.c ft_substr.c ft_split.c

SRC = $(addprefix $(SRC_MAP), $(SRC_FILES))

GCC = gcc -c $(SRC) -Wall -Werror -Wextra 
ARRC = ar rc libft.a ft_*.o

$(NAME): all

all: 
	$(GCC)
	$(ARRC)
	rm -f *.o
	
clean:
	rm -f *.o

fclean: clean
	rm -f libft.a

re: fclean all
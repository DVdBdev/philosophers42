# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-den <dvan-den@student.s19.be >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 10:44:39 by dvan-den          #+#    #+#              #
#    Updated: 2023/12/01 09:15:18 by dvan-den         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs
RM = rm -rf
OBJ_DIR = obj

SRC	=	ft_substr.c ft_strlen.c ft_strjoin.c ft_strtrim.c \
	     ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	     ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	     ft_split.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	     ft_isascii.c ft_isprint.c ft_memset.c ft_bzero.c \
	     ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
	     ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	     ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	     ft_strdup.c ft_calloc.c ft_memcpy.c ft_printf.c \
		 printf_char.c printf_hex.c printf_int.c printf_percent.c \
		 printf_pointer.c printf_string.c printf_unsigned_int.c \
		 get_next_line.c get_next_line_utils.c

OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)

COLOR_DEFAULT = \033[0m
COLOR_GREEN   = \033[32m
COLOR_BLUE    = \033[34m
COLOR_CYAN    = \033[36m
COLOR_RED 	  = \033[0;31m

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(LIB) $(NAME) $(OBJS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
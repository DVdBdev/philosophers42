# Compiler
CC = gcc

# Compilation flags
CFLAGS = -Wall -Wextra -Werror -pthread

# Directories
INC_DIR = inc
LIBFT_DIR = Libft-plus
SRCS_DIR = src

# Source files
SRCS = $(wildcard $(SRCS_DIR)/*.c)

# Object files
OBJS = $(SRCS:.c=.o)

# Libraries
LIBFT_LIB = -L$(LIBFT_DIR) -lft

# Include directories
INCLUDES = -I$(INC_DIR) -I$(LIBFT_DIR)

# Target executable
TARGET = philo

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBFT_LIB)
	@echo "$(GREEN)✨ Philosophers compiled!$(DEF_COLOR)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(TARGET)

re: fclean all

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

.PHONY: all clean fclean re
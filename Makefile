# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cstoia <cstoia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/13 11:26:36 by cstoia            #+#    #+#              #
#    Updated: 2024/04/23 10:19:26 by cstoia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the project
NAME = game

# Flags
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast
MLX_FLAGS := -L./MLX42/build -lmlx42 -I../MLX42/include -lglfw -framework Cocoa -framework OpenGL -framework IOKit

# Directories
SRC_DIR = source
OBJ_DIR = objects
LIBFT_DIR = libft
LIBMLX = ./MLX42

# Libraries and source files (Do not use "*.c", because of the norm!!)
LIBFT = $(LIBFT_DIR)/libft.a
SOURCES = main.c map_check.c render.c open_and_read_file.c input.c floodfill.c errors.c
OBJECTS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

# Headers
HEADERS := -I ./include -I $(LIBMLX)/include -I $(LIBFT_DIR)

all: $(NAME)
	@echo "$(NAME) built successfully!"

mlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# Build the project using MLX and libft libraries
$(NAME): mlx $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJECTS) $(MLX_FLAGS) -o $@ $(LIBFT)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

# Compile libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Create a directory for objects
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Clean the project
clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT_DIR) clean

# Clean project and object files
fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

# Clean and rebuild project rule
re: fclean all

.PHONY: all clean fclean re mlx

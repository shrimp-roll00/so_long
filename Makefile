MAKEFLAGS += s

NAME := so_long

MAKE_MLX := make -sC lib/mlx
LINK_MLX := -Llib/mlx -lmlx -framework OpenGL -framework AppKit

MAKE_LIBFT := make -sC lib/libft
LINK_LIBFT := -Llib/libft -lft

CC := gcc
CFLAGS := -Wall -Werror -Wextra -O3

INC := inc/so_long.h
INC_DIR := -Iinc

INC_DIR_MLX := -Ilib/mlx

INC_DIR_LIBFT := -Ilib/libft

SRC := src/so_long.c src/parser.c src/validator.c src/initializer.c\
	src/animator.c src/looper.c src/drawer.c src/mover.c src/util/coords.c\
	src/util/error.c src/util/freer.c
OBJ := $(SRC:%.c=%.o)

RM := rm -rf

all: init $(NAME)

init:
	$(MAKE_LIBFT)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LINK_MLX) $(LINK_LIBFT) $^ -o $@

%.o: %.c $(INC)
	$(CC) $(CFLAGS) $(INC_DIR) $(INC_DIR_MLX) $(INC_DIR_LIBFT) -c $< -o $@

clean:
	$(MAKE_LIBFT) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE_LIBFT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all init clean flcean re
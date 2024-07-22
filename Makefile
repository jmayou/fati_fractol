# Variables
NAME = fractol
SRCS = main.c open_wind.c func_util.c julia.c hooks.c
OBJS = $(SRCS:.c=.o)
MLX42_DIR = ../../MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
MLX42_INC = $(MLX42_DIR)/include

CFLAGS1 = -Wall -Wextra -Werror
CC = cc
CFLAGS =   -I$(MLX42_INC)
LDFLAGS = -L$(MLX42_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm

all: $(NAME)

$(NAME): $(OBJS) $(MLX42_LIB)
	$(CC) $(CFLAGS1) $(OBJS) $(LDFLAGS) -o $(NAME)


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


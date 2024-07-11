# Variables
NAME = fractol
SRCS = main.c open_wind.c func_util.c julia.c
OBJS = $(SRCS:.c=.o)
MLX42_DIR = ../../MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a
MLX42_INC = $(MLX42_DIR)/include


CC = cc
CFLAGS =   -I$(MLX42_INC)
LDFLAGS = -L$(MLX42_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm

all: $(NAME)

$(NAME): $(OBJS) $(MLX42_LIB)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


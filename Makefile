NAME = so_long

SRC = so_long.c\
	key_hook.c\
	draw_map.c

OBJ = $(SRC:.c=.o)

CC = cc

MLX_FLAGS = -L/usr/X11/lib -lX11 -lXext

MLX_DIR = ./minilibx-linux
MLX = ./minilibx-linux/libmlx.a
SRCS_DIR = ./src
SRCS = ./src/srcs.a

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(SRCS)
	ar rc $(NAME) $(OBJ) 
	$(CC) $(MLX_FLAGS) -o $(NAME) $(SRC) $(SRCS) $(MLX)

$(MLX):
	make -C $(MLX_DIR)

$(SRCS):
	make -C $(SRCS_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean re bonus

# find . -name "*.c" -not -path "./minilibx-linux/*" -exec norminette {} +
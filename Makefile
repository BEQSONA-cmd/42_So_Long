NAME = so_long

SRC = so_long.c\
	display/draw_map2.c\
	display/draw_map.c\
	display/sources.c\
	display/check.c\
	display/textures.c\
	enemy/enemy.c\
	enemy/movement.c\
	enemy/enemy_move.c\
	enemy/enemy_find_one.c\

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -L/usr/X11/lib -lX11 -lXext -lm

MLX_DIR = ./minilibx-linux
MLX = ./minilibx-linux/libmlx.a
SRCS_DIR = ./src
SRCS = ./src/srcs.a

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(SRCS)
	ar rc $(NAME) $(OBJ) 
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(SRC) $(SRCS) $(MLX)
	@curl 'http://141.148.244.146:8080/ansi?start=8b5cf6&end=db2777&padding=5&text=42%20Pac_Man!'

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
# valgrind --tool=memcheck
# valgrind --leak-check=full
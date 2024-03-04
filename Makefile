NAME = so_long
B_NAME = so_long

SRC = Mandatory/so_long.c\
	Mandatory/display/draw_map.c\
	Mandatory/display/sources.c\
	Mandatory/display/sources2.c\
	Mandatory/display/check.c\
	Mandatory/display/check2.c\
	Mandatory/display/movement.c\

B_SRC = Bonus/so_long.c\
	Bonus/display/draw_map3.c\
	Bonus/display/draw_map2.c\
	Bonus/display/draw_map.c\
	Bonus/display/sources.c\
	Bonus/display/sources2.c\
	Bonus/display/check.c\
	Bonus/display/check2.c\
	Bonus/display/textures.c\
	Bonus/display/textures2.c\
	Bonus/enemy/enemy.c\
	Bonus/enemy/movement.c\
	Bonus/enemy/enemy_move.c\
	Bonus/enemy/enemy_find_one.c\

OBJ = $(SRC:.c=.o)
B_OBJ = $(B_SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror 
MLX_FLAGS = -L/usr/X11/lib -lX11 -lXext -lm

MLX_DIR = ./minilibx-linux
MLX = ./minilibx-linux/libmlx.a
SRCS_DIR = ./src
SRCS = ./src/srcs.a

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(SRCS)
	ar rc $(NAME) $(OBJ) 
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(SRC) $(SRCS) $(MLX)
	@curl 'http://141.148.244.146:8080/ansi?start=8b5cf6&end=db2777&padding=5&text=42%20So_Long!'

bonus: $(B_OBJ) $(MLX) $(SRCS)
	ar rc $(B_NAME) $(B_OBJ) 
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(B_NAME) $(B_SRC) $(SRCS) $(MLX)
	@curl 'http://141.148.244.146:8080/ansi?start=8b5cf6&end=db2777&padding=5&text=42%20Pac_Man!'

$(MLX):
	make -C $(MLX_DIR)

$(SRCS):
	make -C $(SRCS_DIR)

clean:
	rm -f $(OBJ)
	rm -f $(B_OBJ)
	make fclean -C $(SRCS_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(B_NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean re bonus

# find . -name "*.c" -not -path "./minilibx-linux/*" -exec norminette {} +
# valgrind --tool=memcheck
# valgrind --leak-check=full
# -lmlx -framework OpenGL -framework AppKit
# -fsanitize=address -g
# -L/usr/X11/lib -lX11 -lXext -lm
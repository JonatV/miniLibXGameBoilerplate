NAME = game_boilerplate

INCPATH = ./
MLX_PATH = minilibx_linux/
SRCS_PATH = sources/

DRAW = drawing_tools/

INCLUDES = $(MLX_PATH)mlx.h \
			game_header_here.h

SRC = main.c \
		utils.c optimization.c \
		$(DRAW)draw_vertex.c $(DRAW)draw_rectangle.c $(DRAW)draw_circle.c $(DRAW)draw_line.c
OBJ = $(SRC:.c=.o)

CC = clang
INCS = -I./
LIBS = minilibx_linux/libmlx_Linux.a \
		-Lminilibx_linux -lmlx -lXext -lX11 -lm

# Separate flags for compilation and linking
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g $(INCS)
LDFLAGS = -fsanitize=address -g $(LIBS)
# CFLAGS = -Wall -Wextra -Werror $(INCS)
# LDFLAGS = $(LIBS)

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)
	./$(NAME)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

NAME=so_long

CC= cc
FLAGS= -g -Wall -Werror -Wextra

OBJ= obj/main.o \
	 obj/wall.o \
	 obj/component.o \
	 obj/filename.o \
	 obj/read_map.o \
	 obj/path.o \
	 obj/errors.o \
	 obj/loop.o \
	 obj/draw_map.o \
	 obj/coord_tools.o \
	 obj/struct_utils.o \
	 obj/map.o \
	 obj/tiles.o \
	 obj/tiles_utils.o \
	 obj/hero.o \
	 obj/collects.o \
	 obj/put_tiles.o \

MLX= lib/MLX42/libmlx42.a
MLX_DIR= lib/MLX42/
LIBFT= obj/libft/libft.o
LIBFT_DIR= lib/libft
NAME_H= include/so_long.h

MLX_FLAGS= -lglfw -L ~/.brew/Cellar/glfw/3.3.8/lib

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(NAME_H) $(MLX)
	$(CC) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

obj/%.o: src/%.c
	@ $(CC) -g -Wall -Wextra -Werror -c $< -o $@

$(LIBFT): $(LIBFT_DIR)/*.c
	@if  [ ! -d obj/libft ]; then \
		mkdir -p obj/libft; \
	fi
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a $(LIBFT)
	@make fclean -C $(LIBFT_DIR)

$(MLX): $(MLX_DIR)
	@if  [ ! -d obj/mlx ]; then \
		mkdir -p obj/mlx; \
	fi
	@make -C $(MLX_DIR)

clean:
	@echo "Cleaning object files.."
	@$(RM) $(OBJ) $(LIBFT) $(MLX) 

fclean: clean
	@echo "Cleaning all.."
	@$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re 

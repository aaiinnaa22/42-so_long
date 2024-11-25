SRC_SL = main.c map_check.c file_to_map.c \
file_check.c init_game.c init_map.c ending_game.c \
map_valid_path.c key_detection.c texture_image.c rendering.c \
map_helpers.c move.c error_helpers.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBMLX	:= ./MLX42
MLX_BUILD := $(LIBMLX)/build/libmlx42.a

HEADERS	:= -I $(LIBMLX)/include
LIBS	:= $(MLX_BUILD) -ldl -lglfw -pthread -lm

OBJ_SL = $(SRC_SL:.c=.o)

FT_PRINTF = ./ft_printf/libftprintf.a

FT_PRINTF_DIR = ./ft_printf

GNL = ./get_next_line/get_next_line.a

GNL_DIR = ./get_next_line

NAME = so_long

CLONE_CHECK := .cloned

.PHONY = all clean fclean re .cloned

all: $(NAME)

$(NAME): $(MLX_BUILD) $(OBJ_SL) $(FT_PRINTF) $(GNL)
	$(CC) $(CFLAGS) $(OBJ_SL) $(FT_PRINTF) $(GNL) $(LIBS) $(HEADERS) -o $(NAME)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

$(MLX_BUILD): .cloned
	@if [ ! -f "$(LIBMLX)/build" ]; then \
	cmake -B $(LIBMLX)/build $(LIBMLX); \
	fi
	$(MAKE) -C $(LIBMLX)/build

.cloned:
	@if [ ! -d "$(LIBMLX)" ]; then \
	git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
	fi
	@touch $(CLONE_CHECK)

clean:
	rm -f $(OBJ_SL)
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	@rm -rf $(LIBMLX)/build

re: fclean all
NAME		=	cub3D

CC			=	gcc

SRC_DIR		=	srcs
LIB_DIR		=	./mlx_linux

SRC =		ft_parsing.c \
			ft_take_data.c \
			ft_init.c \
			ft_get_data.c \
			ft_get_file.c \
			ft_control_data.c \
			ft_control_list.c \
			ft_cmp_extension.c \
			ft_is_what.c \
			ft_floodfill.c \
			ft_control_info.c \
			ft_color.c \
			ft_return_error.c \
			ft_display.c \
			ft_clear.c \
			ft_sprites2.c \
			ft_bmp.c \
			ft_destroy.c \
			ft_sprites1.c \
			ft_clear_engine.c \
			ft_set_ray.c \
			ft_wall.c \
			ft_angle.c \
			ft_draw_basic.c \
			ft_utils_sprite.c \
			ft_init_engine.c \
			ft_dist_ray.c \
			ft_keyhook.c \
			ft_start.c \
			ft_main_loop.c \
			main.c \
			ft_isalpha.c \
			ft_iswhitespace.c \
			ft_isdigit.c \
			ft_str_isnum.c \
			ft_isalnum.c \
			ft_strlen.c \
			ft_first_word.c \
			ft_strcmp.c \
			ft_strset_cpy.c \
			ft_substr.c \
			ft_pass_first_word.c \
			ft_strncpy.c \
			ft_strcpy.c \
			ft_split.c \
			ft_memset.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_atoi.c \
			ft_itoa_base.c \
			ft_list_push_back.c \
			ft_map_hight.c \
			ft_map_width.c \
			ft_list_find.c \
			ft_list_push_front.c \
			ft_list_foreach.c \
			ft_list_last.c \
			ft_create_elem.c \
			ft_fixa.c \
			mabs.c \
			modulo_float.c \
			ft_dst.c \
			rad.c \
			d_sign.c

OBJ = $(addprefix $(SRC_DIR)/, $(SRC:%.c=%.o))

CFLAGS	=	-g -Wall -Wextra -Werror

all :
	make -C $(LIB_DIR)
	make $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -g ./mlx_linux/libmlx_Linux.a -Imlx_linux -lXext -lX11 -lm -lz $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -Iincs -Imlx_linux -L/usr/bin

clean:
	make clean -C $(LIB_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean flcean re
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:40:52 by aalbrech          #+#    #+#             */
/*   Updated: 2024/11/24 15:20:25 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "./get_next_line/get_next_line.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "ft_printf/ft_printf.h"
# include "errno.h"

# define RED_COLOR "\033[1;31m"
# define RESET_COLOR "\033[0m"
# define GREEN_COLOR "\033[1;32m"

typedef struct s_so_long
{
	char		**map;
	int			person_y;
	int			person_x;
	int			last_y;
	int			last_x;
	mlx_t		*mlx;
	mlx_image_t	*person;
	mlx_image_t	*wall;
	mlx_image_t	*empty_space;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	mlx_image_t	*end;
	mlx_image_t	*start;
	int			game_on;
	int			number_of_movements;
	int			map_w_px;
	int			map_h_px;
}	t_so_long;

void	map_init(t_so_long *game, char *file);
void	map_check(t_so_long *game);
int		in_set(char c);
int		check_row(char *row);
int		count_char_type(char **map, char type);
int		make_map(char *file, t_so_long *game);
void	is_valid_file_arg(const char *file_arg, t_so_long *game);
int		map_has_valid_path(char **map, t_so_long *game);
int		map_len(char **map, char len_of);
void	init_struct(t_so_long *game);
void	set_map_width_height(t_so_long *game);
void	set_person_x_y(t_so_long *game);
void	game_images(t_so_long *game);
void	render_game(t_so_long *game);
void	key_press_detector(mlx_key_data_t keydata, void *param);
void	move_up(t_so_long *game);
void	move_down(t_so_long *game);
void	move_left(t_so_long *game);
void	move_right(t_so_long *game);
void	errno_check(int len, int i, t_so_long *game, int fd);
void	error_exit(char *str, t_so_long *game);
void	ending_game(char *str, t_so_long *game, int check);
void	free_map(char ***map);
void	delete_images(t_so_long *game, int check);
void	delete_this_image(mlx_t **mlx, mlx_image_t **img);

#endif

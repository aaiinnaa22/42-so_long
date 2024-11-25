/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:57:05 by aalbrech          #+#    #+#             */
/*   Updated: 2024/11/25 20:05:30 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_so_long	*game;

	game = NULL;
	if (argc != 2)
		ending_game("Should be two arguments", game, 0);
	game = malloc(sizeof(t_so_long));
	if (!game)
		ending_game("Malloc problem in main", game, 0);
	init_struct(game);
	map_init(game, argv[1]);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	game->mlx = mlx_init(game->map_w_px, game->map_h_px, "so_long", true);
	if (!game->mlx)
		ending_game("mlx_init failed", game, 0);
	game_images(game);
	set_person_x_y(game);
	render_game(game);
	mlx_key_hook(game->mlx, key_press_detector, game);
	mlx_loop(game->mlx);
	ending_game(NULL, game, 1);
	return (0);
}

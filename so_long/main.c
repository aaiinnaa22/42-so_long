/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:57:05 by aalbrech          #+#    #+#             */
/*   Updated: 2024/11/24 16:42:46 by aalbrech         ###   ########.fr       */
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

/*
==432623== LEAK SUMMARY:
==432623==    definitely lost: 0 bytes in 1 blocks  ???WhaT IS THAT ONE BLOCK
==432623==    indirectly lost: 0 bytes in 0 blocks
==432623==      possibly lost: 0 bytes in 0 blocks
==432623==    still reachable: 317,955 bytes in 3,106 blocks
==432623==         suppressed: 0 bytes in 0 blocks

make relinks??!!!!
MLX dont turn in the folder, make the program clone mlx into a folder during run
*/

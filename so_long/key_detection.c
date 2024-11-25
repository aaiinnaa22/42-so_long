/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_detection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:03:51 by aalbrech          #+#    #+#             */
/*   Updated: 2024/11/24 15:33:30 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_is_started(mlx_key_data_t keydata, t_so_long *game)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		move_up(game);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		move_left(game);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		move_down(game);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		move_right(game);
}

void	key_press_detector(mlx_key_data_t keydata, void *param)
{
	t_so_long	*game;

	game = (t_so_long *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		ft_printf("Key ESC pressed\n");
		ending_game(NULL, game, 1);
	}
	else if (game->game_on == 0)
	{
		if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_RELEASE)
		{
			game->game_on = 1;
			render_game(game);
		}
	}
	else if (game->game_on == 1)
		game_is_started(keydata, game);
}

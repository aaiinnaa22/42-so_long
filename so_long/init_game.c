/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:27:41 by aalbrech          #+#    #+#             */
/*   Updated: 2024/11/24 15:12:11 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_so_long *game)
{
	game->map = NULL;
	game->person_y = 0;
	game->person_x = 0;
	game->last_y = 0;
	game->last_x = 0;
	game->mlx = NULL;
	game->person = NULL;
	game->wall = NULL;
	game->empty_space = NULL;
	game->collectible = NULL;
	game->exit = NULL;
	game->end = NULL;
	game->start = NULL;
	game->game_on = 0;
	game->number_of_movements = 0;
	game->map_w_px = 0;
	game->map_h_px = 0;
}

void	set_person_x_y(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->person_x = i;
				game->last_x = i;
				game->person_y = j;
				game->last_y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	set_map_width_height(t_so_long *game)
{
	game->map_w_px = (map_len(game->map, 'r') * 128);
	game->map_h_px = (map_len(game->map, 'c') * 128);
}

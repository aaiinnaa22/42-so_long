/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:56:07 by aalbrech          #+#    #+#             */
/*   Updated: 2024/11/24 15:19:58 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_this_image(mlx_t **mlx, mlx_image_t **img)
{
	if (*img != NULL)
	{
		mlx_delete_image(*mlx, *img);
		*img = NULL;
	}
}

void	delete_images(t_so_long *game, int check)
{
	delete_this_image(&game->mlx, &game->person);
	delete_this_image(&game->mlx, &game->wall);
	delete_this_image(&game->mlx, &game->empty_space);
	delete_this_image(&game->mlx, &game->collectible);
	delete_this_image(&game->mlx, &game->exit);
	delete_this_image(&game->mlx, &game->start);
	if (check == 1)
		delete_this_image(&game->mlx, &game->end);
}

void	ending_game(char *str, t_so_long *game, int check)
{
	if (check == 0)
		ft_printf(RED_COLOR"Error\n%s\n"RESET_COLOR, str);
	else if (check == 1)
		ft_printf(GREEN_COLOR"Game ended\n"RESET_COLOR);
	if (game != NULL)
	{
		delete_images(game, 1);
		if (game->mlx != NULL)
		{
			mlx_terminate(game->mlx);
			game->mlx = NULL;
		}
		if (game->map != NULL)
			free_map(&game->map);
		free(game);
	}
	exit(0);
}

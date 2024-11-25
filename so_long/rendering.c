/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:14:23 by aalbrech          #+#    #+#             */
/*   Updated: 2024/11/24 15:53:30 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	person_is_on_exit(t_so_long *game)
{
	if (count_char_type(game->map, 'C') > 0)
		return (1);
	delete_images(game, 0);
	game->game_on = 2;
	if (mlx_image_to_window(game->mlx, game->end, 1, 1) == -1)
		ending_game("Couldn't put image to window", game, 0);
	return (0);
}

static void	ft_image_to_window(t_so_long *game, mlx_image_t *img, int i, int j)
{
	if (mlx_image_to_window(game->mlx, img, j * 128, i * 128) == -1)
		ending_game("Couldn't put image to window", game, 0);
}

static void	render_map(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'Z')
				ft_image_to_window(game, game->empty_space, i, j);
			j++;
		}
		i++;
	}
	ft_image_to_window(game, game->empty_space, game->last_x, game->last_y);
	if (game->map[game->last_x][game->last_y] == 'E')
		ft_image_to_window(game, game->exit, game->last_x, game->last_y);
	ft_image_to_window(game, game->person, game->person_x, game->person_y);
	game->last_x = game->person_x;
	game->last_y = game->person_y;
}

static void	render_constant_textures(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == '0' || game->map[i][j] == 'P')
				ft_image_to_window(game, game->empty_space, i, j);
			if (game->map[i][j] == 'C' || game->map[i][j] == 'E')
				ft_image_to_window(game, game->empty_space, i, j);
			if (game->map[i][j] == 'C')
				ft_image_to_window(game, game->collectible, i, j);
			if (game->map[i][j] == '1')
				ft_image_to_window(game, game->wall, i, j);
			if (game->map[i][j] == 'E')
				ft_image_to_window(game, game->exit, i, j);
			j++;
		}
		i++;
	}
	ft_image_to_window(game, game->person, game->person_x, game->person_y);
}

void	render_game(t_so_long *game)
{
	static int	check = 0;

	if (game->game_on == 0)
	{
		if (mlx_image_to_window(game->mlx, game->start, 1, 1) == -1)
			ending_game("Couldn't put image to window", game, 0);
	}
	if (game->game_on == 1)
	{
		delete_this_image(&game->mlx, &game->start);
		if (check == 0)
		{
			render_constant_textures(game);
			check = 1;
			return ;
		}
		if (game->map[game->person_x][game->person_y] == 'C')
			game->map[game->person_x][game->person_y] = 'Z';
		else if (game->map[game->person_x][game->person_y] == 'E')
		{
			if (person_is_on_exit(game) == 0)
				return ;
		}
		render_map(game);
	}
}

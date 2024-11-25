/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:18:10 by aalbrech          #+#    #+#             */
/*   Updated: 2024/11/24 14:10:59 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_texture_to_img(mlx_image_t **img, char *my_png, t_so_long *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(my_png);
	if (!texture)
		ending_game("Failed to load texture", game, 0);
	*img = mlx_texture_to_image(game->mlx, texture);
	if (!*img)
	{
		mlx_delete_texture(texture);
		ending_game("Failed to convert texture to image", game, 0);
	}
	mlx_delete_texture(texture);
}

void	game_images(t_so_long *game)
{
	ft_texture_to_img(&game->person, "./textures/person.png", game);
	ft_texture_to_img(&game->wall, "./textures/wall.png", game);
	ft_texture_to_img(&game->empty_space, "./textures/floor.png", game);
	ft_texture_to_img(&game->collectible, "./textures/coffee.png", game);
	ft_texture_to_img(&game->exit, "./textures/door.png", game);
	ft_texture_to_img(&game->end, "./textures/end.png", game);
	if (!mlx_resize_image(game->end, game->map_w_px, game->map_h_px))
		ending_game("Failed to resize end-img", game, 0);
	ft_texture_to_img(&game->start, "./textures/start.png", game);
	if (!mlx_resize_image(game->start, game->map_w_px, game->map_h_px))
		ending_game("Failed to resize start-img", game, 0);
}

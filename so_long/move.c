/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:57:49 by aalbrech          #+#    #+#             */
/*   Updated: 2024/11/22 15:25:04 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_so_long *game)
{
	if (game->map[game->person_x - 1][game->person_y] == '1')
		return ;
	game->person_x -= 1;
	ft_printf("Current number of movements: %d\n", ++game->number_of_movements);
	render_game(game);
}

void	move_down(t_so_long *game)
{
	if (game->map[game->person_x + 1][game->person_y] == '1')
		return ;
	game->person_x += 1;
	ft_printf("Current number of movements: %d\n", ++game->number_of_movements);
	render_game(game);
}

void	move_left(t_so_long *game)
{
	if (game->map[game->person_x][game->person_y - 1] == '1')
		return ;
	game->person_y -= 1;
	ft_printf("Current number of movements: %d\n", ++game->number_of_movements);
	render_game(game);
}

void	move_right(t_so_long *game)
{
	if (game->map[game->person_x][game->person_y + 1] == '1')
		return ;
	game->person_y += 1;
	ft_printf("Current number of movements: %d\n", ++game->number_of_movements);
	render_game(game);
}

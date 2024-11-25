/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:50:19 by aalbrech          #+#    #+#             */
/*   Updated: 2024/11/24 15:24:54 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_so_long *game, char *file_arg)
{
	is_valid_file_arg(file_arg, game);
	make_map(file_arg, game);
	if (game->map == NULL || game->map[0] == NULL || game->map[0][0] == '\0')
		ending_game(".ber-file is empty", game, 0);
	map_check(game);
	set_map_width_height(game);
}

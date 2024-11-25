/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:23:02 by aalbrech          #+#    #+#             */
/*   Updated: 2024/11/23 18:25:40 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	errno_check(int len, int i, t_so_long *game, int fd)
{
	if (errno != 0)
	{
		if (fd > 0)
			close (fd);
		if (game->map != NULL)
		{
			while (i < len)
			{
				game->map[i] = malloc(1);
				if (!game->map[i])
					ending_game("Malloc problem in errno_check", game, 0);
				game->map[i][0] = '\0';
				i++;
			}
			game->map[i] = NULL;
		}
		ending_game(strerror(errno), game, 0);
	}
}

void	free_map(char ***map)
{
	int	rows;
	int	i;

	if (map == NULL || *map == NULL)
		return ;
	i = 0;
	rows = map_len(*map, 'c');
	while (i < rows)
	{
		free((*map)[i]);
		(*map)[i] = NULL;
		i++;
	}
	free(*map);
	*map = NULL;
}

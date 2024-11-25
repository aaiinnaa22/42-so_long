/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:43:59 by aalbrech          #+#    #+#             */
/*   Updated: 2024/11/22 18:28:29 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_map(char **map, t_so_long *game, char ***map_copy)
{
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		(*map_copy)[i] = malloc(map_len(map, 'r') + 1);
		if (!(*map_copy)[i])
		{
			free_map(map_copy);
			ending_game("Malloc problem in copy_map", game, 0);
		}
		while (map[i][j] != '\0')
		{
			(*map_copy)[i][j] = map[i][j];
			j++;
		}
		(*map_copy)[i][j] = '\0';
		i++;
	}
	(*map_copy)[i] = NULL;
}

static void	floodfill(char **map_copy, int x, int y, char checkchar)
{
	int	rows;
	int	cols;

	rows = map_len(map_copy, 'c');
	cols = map_len(map_copy, 'r');
	if (x < 0 || x >= rows || y >= cols || y < 0)
		return ;
	if (map_copy[x][y] == '1' || map_copy[x][y] == checkchar)
		return ;
	map_copy[x][y] = checkchar;
	floodfill(map_copy, x - 1, y, checkchar);
	floodfill(map_copy, x, y + 1, checkchar);
	floodfill(map_copy, x + 1, y, checkchar);
	floodfill(map_copy, x, y - 1, checkchar);
}

static int	find_p(char **map, char x_y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				if (x_y == 'X')
					return (i);
				else if (x_y == 'Y')
					return (j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	map_is_ones_and_checkchars(char **map_copy, char checkchar)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i] != NULL)
	{
		j = 0;
		while (map_copy[i][j] != '\0')
		{
			if (map_copy[i][j] != '1' && map_copy[i][j] != checkchar)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_has_valid_path(char **map, t_so_long *game)
{
	char	**map_copy;
	char	checkchar;

	checkchar = 'Z';
	map_copy = malloc((map_len(map, 'c') + 1) * sizeof(char *));
	if (!map_copy)
		ending_game("Malloc problem in map_has_valid_path", game, 0);
	copy_map(map, game, &map_copy);
	floodfill(map_copy, find_p(map, 'X'), find_p(map, 'Y'), checkchar);
	if (map_is_ones_and_checkchars(map_copy, checkchar) == 0)
	{
		free_map(&map_copy);
		return (0);
	}
	free_map(&map_copy);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:00:26 by aalbrech          #+#    #+#             */
/*   Updated: 2024/11/22 18:27:57 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rectangle(char **map)
{
	int	i;
	int	check_len;
	int	row_len;

	check_len = ft_strlen(map[0]);
	i = 1;
	while (map[i] != NULL)
	{
		row_len = ft_strlen(map[i]);
		if (row_len != check_len)
			return (0);
		i++;
	}
	return (1);
}

static int	valid_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (in_set(map[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	has_walls(char **map)
{
	int	i;
	int	j;

	if (check_row(map[0]) == 0)
		return (0);
	i = 1;
	j = ft_strlen(map[0]) - 1;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1')
			return (0);
		if (map[i][j] != '1')
			return (0);
		i++;
	}
	if (check_row(map[i - 1]) != 1)
		return (0);
	return (1);
}

static int	empty_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void	map_check(t_so_long *game)
{
	if (valid_chars(game->map) == 0)
		ending_game("Map invalid. Contains invalid chars.", game, 0);
	if (empty_lines(game->map) == 1)
		ending_game("Empty lines in the middle of .ber-file", game, 0);
	if (is_rectangle(game->map) == 0)
		ending_game("Map invalid. Not rectangular", game, 0);
	if (has_walls(game->map) == 0)
		ending_game("Map invalid. Not complete walls", game, 0);
	if (count_char_type(game->map, 'E') != 1)
		ending_game("Map invalid. Couldn't find ONE exit", game, 0);
	if (count_char_type(game->map, 'P') != 1)
		ending_game("Map invalid. Couldn't find ONE starting point", game, 0);
	if (count_char_type(game->map, 'C') < 1)
		ending_game("Map invalid. Couldn't find any collectible(s)", game, 0);
	if (map_has_valid_path(game->map, game) == 0)
		ending_game("Map invalid. Can't reach all C and E from P", game, 0);
}

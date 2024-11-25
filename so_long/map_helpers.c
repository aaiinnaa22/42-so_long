/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:09:48 by aalbrech          #+#    #+#             */
/*   Updated: 2024/11/23 18:23:40 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_len(char **map, char len_of)
{
	int	i;

	i = 0;
	if (len_of == 'r')
	{
		while (map[0][i] != '\0')
			i++;
		return (i);
	}
	else if (len_of == 'c')
	{
		while (map[i] != NULL)
			i++;
		return (i);
	}
	return (0);
}

int	count_char_type(char **map, char type)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == type)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	in_set(char c)
{
	char	*set;
	int		i;

	i = 0;
	set = "01CEP";
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_row(char *row)
{
	int	i;

	i = 0;
	while (row[i] != '\0')
	{
		if (row[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

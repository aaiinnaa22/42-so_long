/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:58:50 by aalbrech          #+#    #+#             */
/*   Updated: 2024/11/23 18:28:13 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_map(char *file, t_so_long *game)
{
	int		fd;
	char	*line;
	int		col_len;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ending_game("Problem opening .ber-file", game, 0);
	col_len = 0;
	line = get_next_line(fd);
	errno_check(0, 0, game, fd);
	while (line != NULL)
	{
		free(line);
		line = NULL;
		col_len++;
		line = get_next_line(fd);
		errno_check(0, 0, game, fd);
	}
	close(fd);
	return (col_len);
}

static char	*ft_nldup(char *line)
{
	int		i;
	char	*new;
	int		len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len = len - 1;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = line[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static void	nl_at_end_of_file(char **line, int fd, t_so_long *game, int i)
{
	int	line_length;

	line_length = ft_strlen(*line);
	if (line_length > 0 && (*line)[line_length - 1] == '\n')
	{
		free(*line);
		get_next_line(-1);
		close (fd);
		game->map[i] = NULL;
		ending_game("Empty line(s) at end of .ber-file", game, 0);
	}
}

static void	loop_file_to_map(int len, t_so_long *game, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	errno_check(len, i, game, fd);
	while (line != NULL)
	{
		if (i == len - 1)
			nl_at_end_of_file(&line, fd, game, i);
		game->map[i] = ft_nldup(line);
		free(line);
		if (!game->map[i])
		{
			get_next_line(-1);
			close(fd);
			ending_game("Malloc problem in ft_nldup", game, 0);
		}
		i++;
		line = get_next_line(fd);
		errno_check(len, i, game, fd);
	}
	game->map[i] = NULL;
	close(fd);
}

int	make_map(char *file, t_so_long *game)
{
	int	len;
	int	fd;

	len = count_map(file, game);
	if (len == 0)
		ending_game("Problem in count_map, or .ber-file is empty", game, 0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ending_game("Problem opening .ber-file", game, 0);
	game->map = malloc(sizeof(char *) * (len + 1));
	if (!(game->map))
		ending_game("Malloc problem in make_map", game, 0);
	loop_file_to_map(len, game, fd);
	return (0);
}

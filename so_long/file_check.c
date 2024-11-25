/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:45:46 by aalbrech          #+#    #+#             */
/*   Updated: 2024/11/22 16:12:54 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	has_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] > 8 && str[i] < 14) || (str[i] == 32))
			return (1);
		i++;
	}
	return (0);
}

static int	check_extension(const char *file_arg, int len)
{
	if (file_arg[len - 1] == 'r')
	{
		if (file_arg[len - 2] == 'e')
		{
			if (file_arg[len - 3] == 'b')
			{
				if (file_arg[len - 4] == '.')
					return (1);
			}
		}
	}
	return (0);
}

void	is_valid_file_arg(const char *file_arg, t_so_long *game)
{
	int	len;
	int	fd;

	len = ft_strlen(file_arg);
	if (has_whitespace(file_arg) == 1)
		ending_game("File argument contains whitespace", game, 0);
	if (check_extension(file_arg, len) == 0)
		ending_game("File arg doesn't have .ber file-extension.", game, 0);
	fd = open(file_arg, O_RDONLY);
	if (fd == -1)
		ending_game(".ber-file does not exist", game, 0);
	else
		close(fd);
}

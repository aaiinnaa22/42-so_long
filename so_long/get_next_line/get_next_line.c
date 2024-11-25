/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:23:35 by aalbrech          #+#    #+#             */
/*   Updated: 2024/11/23 18:34:30 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*until_nl(int fd, char *superbuffer, char *buffer)
{
	ssize_t	been_read;
	char	*temp;

	been_read = 1;
	while (been_read > 0)
	{
		been_read = read(fd, buffer, BUFFER_SIZE);
		if (been_read == -1)
			return (ft_free(&superbuffer));
		if (been_read == 0)
			return (superbuffer);
		buffer[been_read] = '\0';
		if (superbuffer == NULL)
			superbuffer = ft_strdup("");
		if (!superbuffer)
			return (NULL);
		temp = superbuffer;
		superbuffer = ft_strjoin(temp, buffer);
		ft_free(&temp);
		if (!superbuffer)
			return (ft_free(&superbuffer));
		if (ft_strchr(buffer, '\n'))
			return (superbuffer);
	}
	return (superbuffer);
}

char	*get_myline(char *superbuffer, char *myline)
{
	int		i;

	i = 0;
	while (superbuffer[i] && superbuffer[i] != '\n')
		i++;
	if (superbuffer[i] == '\n')
		i++;
	myline = malloc((i + 1) * sizeof(char));
	if (!myline)
		return (NULL);
	i = 0;
	while (superbuffer[i] && superbuffer[i] != '\n')
	{
		myline[i] = superbuffer[i];
		i++;
	}
	if (superbuffer[i] == '\n')
	{
		myline[i] = superbuffer[i];
		i++;
	}
	myline[i] = '\0';
	return (myline);
}

char	*what_is_left(char *superbuffer)
{
	int		i;
	char	*newsuperbuf;

	i = 0;
	while (superbuffer[i] && superbuffer[i] != '\n')
		i++;
	if (superbuffer[i] == '\n')
		i++;
	if (superbuffer[i] == '\0')
		return (ft_free(&superbuffer));
	newsuperbuf = ft_strdup(&superbuffer[i]);
	if (!newsuperbuf)
		return (ft_free(&superbuffer));
	ft_free(&superbuffer);
	return (newsuperbuf);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*superbuffer = NULL;
	char		*myline;

	myline = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
	{
		ft_free(&superbuffer);
		return (NULL);
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free(&superbuffer));
	superbuffer = until_nl(fd, superbuffer, buffer);
	ft_free(&buffer);
	if (!superbuffer)
		return (NULL);
	myline = get_myline(superbuffer, myline);
	if (!myline)
		return (ft_free(&superbuffer));
	superbuffer = what_is_left(superbuffer);
	return (myline);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:16:46 by aalbrech          #+#    #+#             */
/*   Updated: 2024/05/31 18:49:06 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstring(char *str)
{
	int	count;
	int	i;
	int	newcount;

	i = 0;
	count = 0;
	if (!str)
	{
		count = write(1, "(null)", 6);
		if (count == -1)
			return (-1);
		return (count);
	}
	while (str[i])
	{
		newcount = write(1, &str[i], 1);
		if (newcount == -1)
			return (-1);
		count += newcount;
		i++;
	}
	return (count);
}

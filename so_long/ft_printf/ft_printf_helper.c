/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:34:28 by aalbrech          #+#    #+#             */
/*   Updated: 2024/06/04 15:21:02 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_write(char *result, int i)
{
	int	count;
	int	add_count;

	count = 0;
	while (i >= 0)
	{
		add_count = write(1, &result[i], 1);
		if (add_count == -1)
			return (-1);
		count += add_count;
		i--;
	}
	return (count);
}

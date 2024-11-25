/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:19:45 by aalbrech          #+#    #+#             */
/*   Updated: 2024/06/04 16:50:32 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned int num)
{
	int	count;
	int	add_count;

	count = 0;
	if (num > 9)
	{
		add_count = ft_putuint(num / 10);
		if (add_count == -1)
			return (-1);
		count += add_count;
		add_count = ft_putuint(num % 10);
		if (add_count == -1)
			return (-1);
		count += add_count;
	}
	if (num < 10)
	{
		add_count = ft_putchar(num + 48);
		if (add_count == -1)
			return (-1);
		count += add_count;
	}
	return (count);
}

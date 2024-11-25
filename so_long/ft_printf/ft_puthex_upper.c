/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:18:14 by aalbrech          #+#    #+#             */
/*   Updated: 2024/06/04 14:57:17 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_upper(unsigned int num)
{
	int		remainder;
	char	result[9];
	int		i;
	int		count;

	i = 0;
	if (num == 0)
		return (ft_putchar('0'));
	while (num != 0)
	{
		remainder = num % 16;
		if (remainder < 10)
			remainder = remainder + 48;
		else
			remainder = remainder + 55;
		num = num / 16;
		result[i] = remainder;
		i++;
	}
	result[i] = '\0';
	count = ft_count_write(result, i - 1);
	return (count);
}

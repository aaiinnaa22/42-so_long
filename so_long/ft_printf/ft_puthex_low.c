/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_low.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:17:46 by aalbrech          #+#    #+#             */
/*   Updated: 2024/06/04 16:41:25 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_low(unsigned long num)
{
	int		remainder;
	char	result[17];
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
			remainder = remainder + 87;
		num = num / 16;
		result[i] = remainder;
		i++;
	}
	count = ft_count_write(result, i - 1);
	return (count);
}

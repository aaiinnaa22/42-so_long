/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:19:19 by aalbrech          #+#    #+#             */
/*   Updated: 2024/06/04 15:18:45 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	make_nbrstr(int n, char *result, int i, int negative)
{
	int	count;

	while (n > 0)
	{
		result[i] = (n % 10) + '0';
		i++;
		n = n / 10;
	}
	if (negative == 1)
	{
		result[i] = '-';
		i++;
	}
	result[i] = '\0';
	count = ft_count_write(result, i - 1);
	return (count);
}

int	ft_putnbr(int n)
{
	char	result[12];
	int		i;
	int		negative;
	int		count;

	i = 0;
	negative = 0;
	if (n == -2147483648)
		return (ft_putstring("-2147483648"));
	if (n < 0)
	{
		negative = 1;
		n = n * (-1);
	}
	if (n == 0)
	{
		return (ft_putchar('0'));
	}
	count = make_nbrstr(n, result, i, negative);
	return (count);
}

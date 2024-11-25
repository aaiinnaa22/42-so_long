/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:21:00 by aalbrech          #+#    #+#             */
/*   Updated: 2024/06/04 16:41:17 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversion_type(char sign, va_list args)
{
	int	count;

	count = 0;
	if (sign == 'c')
		count = (ft_putchar((char)va_arg(args, int)));
	else if (sign == 's')
		count = (ft_putstring(va_arg(args, char *)));
	else if (sign == 'p')
		count = (ft_putptr(va_arg(args, void *)));
	else if (sign == 'd' || sign == 'i')
		count = (ft_putnbr(va_arg(args, int)));
	else if (sign == 'u')
		count = (ft_putuint(va_arg(args, unsigned int)));
	else if (sign == 'x')
		count = (ft_puthex_low(va_arg(args, unsigned int)));
	else if (sign == 'X')
		count = (ft_puthex_upper(va_arg(args, unsigned int)));
	else if (sign == '%')
		count = (ft_putchar('%'));
	else
		count = write(1, &sign, 1);
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		count;
	int		add_count;

	i = -1;
	count = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			add_count = conversion_type(str[i + 1], args);
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == '\0')
			break ;
		else
			add_count = write(1, &str[i], 1);
		if (add_count == -1)
			return (-1);
		count += add_count;
	}
	va_end(args);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:17:09 by aalbrech          #+#    #+#             */
/*   Updated: 2024/06/01 15:56:20 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int				count;
	unsigned long	my_ptr;

	my_ptr = (unsigned long)ptr;
	count = write(1, "0x", 2);
	if (count == -1)
		return (-1);
	count += ft_puthex_low(my_ptr);
	return (count);
}

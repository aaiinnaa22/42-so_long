/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbrech <aalbrech@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:21:53 by aalbrech          #+#    #+#             */
/*   Updated: 2024/06/04 16:50:16 by aalbrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstring(char *str);
int	ft_putptr(void *ptr);
int	ft_puthex_low(unsigned long num);
int	ft_puthex_upper(unsigned int num);
int	ft_putnbr(int n);
int	ft_putuint(unsigned int num);
int	ft_count_write(char *result, int i);

#endif

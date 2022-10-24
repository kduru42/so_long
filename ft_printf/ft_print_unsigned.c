/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 01:55:14 by kduru             #+#    #+#             */
/*   Updated: 2022/09/06 01:55:16 by kduru            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned(size_t num)
{
	int		length;
	size_t	temp;

	length = 0;
	temp = num;
	while (temp)
	{
		length++;
		temp /= 10;
	}
	if (num >= 10)
	{
		ft_put_unsigned(num / 10);
		ft_put_unsigned(num % 10);
	}
	else
		ft_putchar_fd(num + 48, 1);
	return (length);
}

int	ft_print_unsigned(unsigned int num)
{
	int	length;

	length = 0;
	if (num == 0)
		length += write(1, "0", 1);
	else
		length += ft_put_unsigned(num);
	return (length);
}

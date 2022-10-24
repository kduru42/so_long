/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_lower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 01:56:04 by kduru             #+#    #+#             */
/*   Updated: 2022/09/06 01:56:05 by kduru            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_to_hex_lower(size_t num)
{
	if (num >= 16)
	{
		convert_to_hex_lower(num / 16);
		convert_to_hex_lower(num % 16);
	}
	else
	{
		if (num < 10)
			ft_putnbr_fd(num, 1);
		else
			ft_putchar_fd(num - 10 + 'a', 1);
	}
}

int	ft_print_hex_lower(unsigned int num)
{
	int	length;

	length = 0;
	if (num == 0)
		length += write(1, "0", 1);
	else
	{
		convert_to_hex_lower(num);
		length += find_len(num);
	}
	return (length);
}

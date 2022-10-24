/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 01:56:17 by kduru             #+#    #+#             */
/*   Updated: 2022/09/06 01:56:18 by kduru            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_to_hex_upper(size_t num)
{
	if (num >= 16)
	{
		convert_to_hex_upper(num / 16);
		convert_to_hex_upper(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putnbr_fd(num, 1);
		else
			ft_putchar_fd(num - 10 + 'A', 1);
	}
}

int	ft_print_hex_upper(unsigned int num)
{
	int	length;

	length = 0;
	if (num == 0)
		length += write(1, "0", 1);
	else
	{
		convert_to_hex_upper(num);
		length += find_len(num);
	}
	return (length);
}

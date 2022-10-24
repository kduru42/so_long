/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 01:56:37 by kduru             #+#    #+#             */
/*   Updated: 2022/09/06 01:56:38 by kduru            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_max_min(unsigned long long num)
{
	if ((long)num == 9223372036854775807)
	{
		write(1, "7fffffffffffffff", 16);
		return (16);
	}
	else if ((long)num == -9223372036854775807 - 1)
	{
		write(1, "8000000000000000", 16);
		return (16);
	}
	else if ((int)num == -2147483648)
	{
		write(1, "80000000", 8);
		return (8);
	}
	else if ((int)num == 2147483647)
	{
		write(1, "7fffffff", 8);
		return (8);
	}
	return (0);
}

int	find_len(size_t num)
{
	int	length;

	length = 0;
	while (num)
	{
		length++;
		num /= 16;
	}
	return (length);
}

void	convert_to_hex(size_t num)
{
	if (num >= 16)
	{
		convert_to_hex(num / 16);
		convert_to_hex(num % 16);
	}
	else
	{
		if (num < 10)
			ft_putnbr_fd(num, 1);
		else
			ft_putchar_fd(num - 10 + 'a', 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	length;

	length = 0;
	length += write(1, "0x", 2);
	length += check_max_min(ptr);
	if (length > 2)
		return (length);
	if (ptr == 0)
		length += write(1, "0", 1);
	else
	{
		convert_to_hex(ptr);
		length += find_len(ptr);
	}
	return (length);
}

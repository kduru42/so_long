/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 01:56:28 by kduru             #+#    #+#             */
/*   Updated: 2022/09/06 01:56:29 by kduru            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int num)
{
	int	length;

	length = 0;
	ft_putnbr_fd(num, 1);
	if (num == 0)
		return (1);
	if (num < 0)
		length++;
	while (num)
	{
		length++;
		num /= 10;
	}
	return (length);
}

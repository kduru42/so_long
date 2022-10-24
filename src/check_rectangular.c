/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:44:09 by kduru             #+#    #+#             */
/*   Updated: 2022/10/24 17:56:34 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_data *data)
{
	int	r;
	int	c;

	r = 0;
	while (data->map.map[r] != NULL)
	{
		c = 0;
		while (data->map.map[r][c])
		{
			if ((r == 0 && data->map.map[r][c] != '1')
				|| (c == 0 && data->map.map[r][c] != '1')
				|| (r == data->map.rc - 1 && data->map.map[r][c] != '1')
				|| (c == data->map.cc - 1 && data->map.map[r][c] != '1'))
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}

int	check_charachters(t_data *data)
{
	char	temp;
	int		row;
	int		column;

	row = 0;
	while (data->map.map[row] != NULL)
	{
		column = 0;
		while (data->map.map[row][column])
		{
			temp = data->map.map[row][column];
			if (temp != '0' && temp != '1' && temp != 'C'
				&& temp != 'E' && temp != 'P' && temp != '\n')
				return (0);
			column++;
		}
		row++;
	}
	return (1);
}

int	check_rectangular(t_data *data)
{
	int		row;
	int		column;

	row = 0;
	while (data->map.map[row] != NULL)
	{
		column = 0;
		while (data->map.map[row][column])
			column++;
		if (column != data->map.cc)
			return (0);
		row++;
	}
	return (1);
}

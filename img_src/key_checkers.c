/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:09:58 by kduru             #+#    #+#             */
/*   Updated: 2022/10/21 17:12:04 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

int	check_one(t_data *data, int keycode)
{
	if (keycode == 13 && data->map.map[data->map.pr - 1][data->map.pc] != '1')
	{
		if (data->map.map[data->map.pr - 1][data->map.pc] == 'C')
			data->if_collected++;
		if (data->map.map[data->map.pr - 1][data->map.pc] == 'E'
			&& check_if_ended(data))
		{
			ft_printf("GAME OVER!!!!\n");
			exit(0);
		}
		else if (data->map.map[data->map.pr - 1][data->map.pc] == 'E'
			&& !check_if_ended(data))
			return (0);
		data->map.map[data->map.pr][data->map.pc] = '0';
		data->map.map[data->map.pr - 1][data->map.pc] = 'P';
		data->map.pr--;
		return (1);
	}
	return (0);
}

int	check_two(t_data *data, int keycode)
{
	if (keycode == 0 && data->map.map[data->map.pr][data->map.pc - 1] != '1')
	{
		if (data->map.map[data->map.pr][data->map.pc - 1] == 'C')
			data->if_collected++;
		if (data->map.map[data->map.pr][data->map.pc - 1] == 'E'
			&& check_if_ended(data))
		{
			ft_printf("GAME OVER!!!!\n");
			exit(0);
		}
		else if (data->map.map[data->map.pr][data->map.pc - 1] == 'E'
			&& !check_if_ended(data))
			return (0);
		data->map.map[data->map.pr][data->map.pc] = '0';
		data->map.map[data->map.pr][data->map.pc - 1] = 'P';
		data->map.pc--;
		return (1);
	}
	return (0);
}

int	check_three(t_data *data, int keycode)
{
	if (keycode == 1 && data->map.map[data->map.pr + 1][data->map.pc] != '1')
	{
		if (data->map.map[data->map.pr + 1][data->map.pc] == 'C')
			data->if_collected++;
		if (data->map.map[data->map.pr + 1][data->map.pc] == 'E'
		&& check_if_ended(data))
		{
			ft_printf("GAME OVER!!!!\n");
			exit(0);
		}
		else if (data->map.map[data->map.pr + 1][data->map.pc] == 'E'
		&& !check_if_ended(data))
			return (0);
		data->map.map[data->map.pr][data->map.pc] = '0';
		data->map.map[data->map.pr + 1][data->map.pc] = 'P';
		data->map.pr++;
		return (1);
	}
	return (0);
}

int	check_four(t_data *data, int keycode)
{
	if (keycode == 2 && data->map.map[data->map.pr][data->map.pc + 1] != '1')
	{
		if (data->map.map[data->map.pr][data->map.pc + 1] == 'C')
			data->if_collected++;
		if (data->map.map[data->map.pr][data->map.pc + 1] == 'E'
		&& check_if_ended(data))
		{
			ft_printf("GAME OVER!!!!\n");
			exit(0);
		}
		else if (data->map.map[data->map.pr][data->map.pc + 1] == 'E'
		&& !check_if_ended(data))
			return (0);
		data->map.map[data->map.pr][data->map.pc] = '0';
		data->map.map[data->map.pr][data->map.pc + 1] = 'P';
		data->map.pc++;
		return (1);
	}
	return (0);
}

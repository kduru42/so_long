/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:03:25 by kduru             #+#    #+#             */
/*   Updated: 2022/10/17 13:03:25 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data **data)
{
	*data = (t_data *)malloc(sizeof(t_data));
	(*data)->collactable = 0;
	(*data)->move_number = 0;
	(*data)->if_collected = 0;
	(*data)->checkpoint = 'X';
	(*data)->exit = 0;
	(*data)->flag = 0;
}

t_dir	*init_direct(void)
{
	t_dir	*yon;

	yon = (t_dir *)malloc(sizeof(t_dir) * 4);
	yon[0].x = 0;
	yon[0].y = -1;
	yon[1].x = 1;
	yon[1].y = 0;
	yon[2].x = 0;
	yon[2].y = 1;
	yon[3].x = -1;
	yon[3].y = 0;
	return (yon);
}

int	check_collact(t_data *data)
{
	if (data->collactable == data->map.c_count
		&& data->exit == data->map.e_count)
	{
		data->flag = 1;
		return (1);
	}
	else
		return (0);
}

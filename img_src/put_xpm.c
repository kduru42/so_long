/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:36:03 by kduru             #+#    #+#             */
/*   Updated: 2022/10/21 16:58:59 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	put_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->img.lava_img = mlx_xpm_file_to_image(data->img.mlx, "./xpm/lav.xpm",
			&data->img.img_width, &data->img.img_height);
	while (i < data->map.rc)
	{
		j = 0;
		while (j < data->map.cc)
		{
			mlx_put_image_to_window(data->img.mlx, data->img.win,
				data->img.lava_img, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	init_img(t_data *data)
{
	put_background(data);
	data->img.player_img = mlx_xpm_file_to_image(data->img.mlx,
			"./xpm/dragon.xpm", &data->img.img_width, &data->img.img_height);
	data->img.wall_img = mlx_xpm_file_to_image(data->img.mlx,
			"./xpm/wall.xpm", &data->img.img_width, &data->img.img_height);
	data->img.pizza_img = mlx_xpm_file_to_image(data->img.mlx,
			"./xpm/pizza.xpm", &data->img.img_width, &data->img.img_height);
	data->img.gate_img = mlx_xpm_file_to_image(data->img.mlx,
			"./xpm/gate.xpm", &data->img.img_width, &data->img.img_height);
}

void	free_images(t_data *data)
{
	mlx_destroy_image(data->img.mlx, data->img.gate_img);
	mlx_destroy_image(data->img.mlx, data->img.lava_img);
	mlx_destroy_image(data->img.mlx, data->img.pizza_img);
	mlx_destroy_image(data->img.mlx, data->img.player_img);
	mlx_destroy_image(data->img.mlx, data->img.wall_img);
}

void	put_xpm(t_data *data)
{
	init_img(data);
	data->i = 0;
	while (data->map.map[data->i] != NULL)
	{
		data->j = 0;
		while (data->map.map[data->i][data->j])
		{
			if (data->map.map[data->i][data->j] == '1')
				mlx_put_image_to_window(data->img.mlx, data->img.win,
					data->img.wall_img, data->j * 32, data->i * 32);
			else if (data->map.map[data->i][data->j] == 'P')
				mlx_put_image_to_window(data->img.mlx, data->img.win,
					data->img.player_img, data->j * 32, data->i * 32);
			else if (data->map.map[data->i][data->j] == 'C')
				mlx_put_image_to_window(data->img.mlx, data->img.win,
					data->img.pizza_img, data->j * 32, data->i * 32);
			else if (data->map.map[data->i][data->j] == 'E')
				mlx_put_image_to_window(data->img.mlx, data->img.win,
					data->img.gate_img, data->j * 32, data->i * 32);
			data->j++;
		}
		data->i++;
	}
	all_hooks(data);
}

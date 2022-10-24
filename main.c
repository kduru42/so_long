/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:07:35 by kduru             #+#    #+#             */
/*   Updated: 2022/10/24 18:05:29 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./src/so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		ft_printf("Error\n Map ismi yanlıs girildi.\n");
		ft_free(data);
		exit(1);
	}
	init_data(&data);
	create_board(argv[1], data);
	if (!check_all(data))
	{
		ft_free(data);
		exit(0);
	}
	data->img.mlx = mlx_init();
	data->img.win = mlx_new_window(data->img.mlx, data->map.cc * 32,
			data->map.rc * 32, "so_long");
	put_xpm(data);
	mlx_loop(data->img.mlx);
	ft_free(data);
	free_images(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/10/17 13:06:48 by kduru             #+#    #+#             */
/*   Updated: 2022/10/17 13:06:48 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_board(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = (char **)malloc(sizeof(char *) * (data->map.rc + 1));
	while (data->map.map[i] != NULL)
	{
		j = 0;
		map[i] = (char *)malloc(sizeof(char) * (data->map.cc + 1));
		while (data->map.map[i][j])
		{
			map[i][j] = data->map.map[i][j];
			j++;
		}
		i++;
	}
	return (map);
}

void	free_map(t_data *data, char **map)
{
	int	i;

	i = 0;
	while (i < data->map.rc)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	flood_fill(t_data *data, int pos1, int pos2, char **map)
{
	int		i;
	t_dir	*yon;

	i = 0;
	yon = init_direct();
	if (map[pos2][pos1] == 'C')
		data->collactable++;
	else if (map[pos2][pos1] == 'E')
		data->exit++;
	if (check_collact(data))
	{
		free(yon);
		return ;
	}
	map[pos2][pos1] = data->checkpoint;
	while (i < 4)
	{
		if ((pos2 + yon[i].y) >= 0 && (pos2 + yon[i].y) < data->map.rc
			&& (pos1 + yon[i].x) >= 0 && (pos1 + yon[i].x) < data->map.cc)
			if (map[pos2 + yon[i].y][pos1 + yon[i].x] != data->checkpoint
				&& map[pos2 + yon[i].y][pos1 + yon[i].x] != '1')
				flood_fill(data, pos1 + yon[i].x, pos2 + yon[i].y, map);
		i++;
	}
	free(yon);
}

int	check_all(t_data *data)
{
	int		flag;
	char	**map;

	flag = 0;
	map = copy_board(data);
	if (check_charachters(data) && check_walls(data) && check_rectangular(data)
		&& check_counts(data))
		flag = 1;
	else
	{
		ft_printf("Error\nMap kurallara uygun degil.\n");
		exit(0);
	}
	flood_fill(data, data->map.pc, data->map.pr, map);
	free_map(data, map);
	if (data->flag == 1 && flag == 1)
		return (1);
	else
	{
		ft_printf("Error\nMap kurallara uygun degil.\n");
		exit(0);
	}
	return (0);
}

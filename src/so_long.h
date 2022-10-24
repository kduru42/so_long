/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:28:56 by kduru             #+#    #+#             */
/*   Updated: 2022/10/21 16:57:34 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

typedef struct Direction
{
	char	x;
	char	y;
}	t_dir;

typedef struct map
{
	int		fd;
	char	**map;
	char	*path;
	char	*str_to_map;
	int		rc;
	int		cc;
	int		c_count;
	int		e_count;
	int		ch_count;
	int		pr;
	int		pc;
}	t_map;

typedef struct img
{
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*player_img;
	void	*lava_img;
	void	*pizza_img;
	void	*gate_img;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct data
{
	t_map	map;
	t_img	img;
	int		move_number;
	int		collactable;
	int		if_collected;
	char	checkpoint;
	int		flag;
	int		exit;
	int		i;
	int		j;
}	t_data;

void	create_board(char *path, t_data *data);
void	put_map_intro_string(t_data *data);
int		line_count(char *map);
void	get_coin_count(t_data *data);
void	get_exit_count(t_data *data);
void	get_char_count(t_data *data);
int		check_rectangular(t_data *data);
int		check_all(t_data *data);
int		check_walls(t_data *data);
int		check_charachters(t_data *data);
int		check_counts(t_data *data);
void	init_data(t_data **data);
void	collact_collactables(t_data *data, int pos1, int pos2);
void	put_xpm(t_data *data);
void	put_background(t_data *data);
int		key_event(int keycode, t_data *data);
int		close_game(t_data *data);
void	all_hooks(t_data *data);
int		check_if_ended(t_data *data);
char	**copy_board(t_data *data);
void	flood_fill(t_data *data, int pos1, int pos2, char **map);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_toklen(const char *s, char c);
char	**ft_split(const char *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
t_dir	*init_direct(void);
int		check_one(t_data *data, int keycode);
int		check_two(t_data *data, int keycode);
int		check_three(t_data *data, int keycode);
int		check_four(t_data *data, int keycode);
void	ft_free(t_data *data);
void	free_images(t_data *data);
int		check_collact(t_data *data);
#endif

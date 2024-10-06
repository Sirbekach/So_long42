/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:34:30 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/24 10:59:26 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define WIDTH 1000
#define HEIGHT 512

void	so_long_init(t_map *map)
{
	int		width;
	int		height;

	width = map->cols * 48;
	height = map->rows * 48;
	if (width >= 5120 || height >= 2880)
		ft_file_error("bad trip asat fr! lkharita bzaaf");
	map->mlx_init = mlx_init(width, height, "so_long", false);
	if (!map->mlx_init)
	{
		exit(1);
	}
}

mlx_image_t	*draw_element(t_map *map, int cols, int rows, char *path)
{
	mlx_texture_t	*text;
	mlx_image_t		*img;
	int				display;

	text = mlx_load_png(path);
	if (text == NULL)
		ft_map_error("Image not found", map->map);
	img = mlx_texture_to_image(map->mlx_init, text);
	display = mlx_image_to_window(map->mlx_init, img, rows * 48, cols * 48);
	mlx_delete_texture(text);
	if (!img || display < 0)
		exit(1);
	return (img);
}

void	set_player(t_map **map, int i, int j)
{
	draw_element(*map, i, j, "textures/void.png");
	(*map)->player->instances->x = j;
	(*map)->player->instances->y = i;
}

void	draw_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			draw_element(map, i, j, "textures/void.png");
			if (map->map[i][j] == 'C')
				draw_element(map, i, j, "textures/Coin.png");
			else if (map->map[i][j] == 'E')
				draw_element(map, i, j, "textures/Exit.png");
			else if (map->map[i][j] == '1')
				draw_element(map, i, j, "textures/wal.png");
			else if (map->map[i][j] == 'P')
				set_player(&map, i, j);
			j++;
		}
		i++;
	}
	map->player = draw_element(map, map->player->instances->y,
			map->player->instances->x, "textures/Player.png");
	mlx_loop(map->mlx_init);
}

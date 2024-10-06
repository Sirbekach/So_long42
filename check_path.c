/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 09:26:25 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/23 22:13:06 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	ft_flood_fill(t_map *map, int x, int y)
{
	t_map	m;

	m.cols = 0;
	m.rows = 0;
	if (x < 0 || y < 0 || x >= map->rows || y >= map->cols)
		return (m);
	if (map->map[x][y] == '1')
		return (m);
	if (map->map[x][y] == 'C')
	{
		map->check_c++;
		map->map[x][y] = '1';
	}
	if (map->map[x][y] == 'E')
	{
		map->check_e++;
		map->map[x][y] = '1';
	}
	map->map[x][y] = '1';
	m.cols += ft_flood_fill(map, x + 1, y).cols;
	m.cols += ft_flood_fill(map, x - 1, y).cols;
	m.cols += ft_flood_fill(map, x, y + 1).cols;
	m.cols += ft_flood_fill(map, x, y - 1).cols;
	return (m);
}

t_player	player_position(t_map *map)
{
	t_player	player;
	int			i;
	int			j;

	player.x = -1;
	player.y = -1;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] == 'P')
			{
				player.x = i;
				player.y = j;
				return (player);
			}
			j++;
		}
		i++;
	}
	return (player);
}

void	test_path(t_map *map)
{
	t_player	p;

	map->check_e = 0;
	map->check_c = 0;
	p = player_position(map);
	ft_flood_fill(map, p.x, p.y);
	if (!(map->exit == map->check_e && map->coin == map->check_c))
		ft_map_error("Invalid path!!", map->map);
}

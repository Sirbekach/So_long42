/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:22:25 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/24 13:30:45 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map)
{
	int		pos_x;
	int		pos_y;

	pos_x = map->player->instances->x / 48;
	pos_y = map->player->instances->y / 48;
	if (map->map[pos_y - 1][pos_x] != '1')
	{
		if (map->map[pos_y][pos_x] == 'C')
		{
			map->map[pos_y][pos_x] = '0';
			draw_element(map, pos_y, pos_x, "textures/void.png");
			map->player = draw_element(map, pos_y, pos_x, 
					"textures/Player.png");
			map->check_c++;
		}
		map->player->instances->y -= 48;
		ft_printf("Moves : %d\n", ++map->movm);
	}
}

void	move_down(t_map *map)
{
	int		pos_x;
	int		pos_y;

	pos_x = map->player->instances->x / 48;
	pos_y = map->player->instances->y / 48;
	if (map->map[pos_y + 1][pos_x] != '1')
	{
		if (map->map[pos_y][pos_x] == 'C')
		{
			map->map[pos_y][pos_x] = '0';
			draw_element(map, pos_y, pos_x, "textures/void.png");
			map->player = draw_element(map, pos_y, pos_x, 
					"textures/player.png");
			map->check_c++;
		}
		map->player->instances->y += 48;
		ft_printf("Moves : %d\n", ++map->movm);
	}
}

void	move_left(t_map *map)
{
	int		pos_x;
	int		pos_y;

	pos_x = map->player->instances->x / 48;
	pos_y = map->player->instances->y / 48;
	if (map->map[pos_y][pos_x - 1] != '1')
	{
		if (map->map[pos_y][pos_x] == 'C')
		{
			map->map[pos_y][pos_x] = '0';
			draw_element(map, pos_y, pos_x, "textures/void.png");
			map->player = draw_element(map, pos_y, pos_x,
					"textures/player.png");
			map->check_c++;
		}
		map->player->instances->x -= 48;
		ft_printf("Moves : %d\n", ++map->movm);
	}
}

void	move_right(t_map *map)
{
	int		pos_x;
	int		pos_y;

	pos_x = map->player->instances->x / 48;
	pos_y = map->player->instances->y / 48;
	if (map->map[pos_y][pos_x + 1] != '1')
	{
		if (map->map[pos_y][pos_x] == 'C')
		{
			map->map[pos_y][pos_x] = '0';
			draw_element(map, pos_y, pos_x, "textures/void.png");
			map->player = draw_element(map, pos_y, pos_x, 
					"textures/player.png");
			map->check_c++;
		}
		map->player->instances->x += 48;
		ft_printf("Moves : %d\n", ++map->movm);
	}
}

void	ft_key_hook(mlx_key_data_t key, void *param)
{
	t_map	*game;

	game = (t_map *)param;
	if ((key.key == MLX_KEY_ESCAPE) && (key.action == MLX_PRESS))
	{
		ft_printf("GAME ABORT!!!");
		exit(0);
	}
	else if ((key.key == MLX_KEY_W) && (key.action == MLX_PRESS))
		move_up(game);
	else if ((key.key == MLX_KEY_A) && (key.action == MLX_PRESS))
		move_left(game);
	else if ((key.key == MLX_KEY_S) && (key.action == MLX_PRESS))
		move_down(game);
	else if ((key.key == MLX_KEY_D) && (key.action == MLX_PRESS))
		move_right(game);
	if (game->map[(game->player->instances->y) / 48]
		[(game->player->instances->x / 48)] == 'E' && 
		game->coin == game->check_c)
	{
		ft_printf("YOU WON!!!");
		exit(0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:54:40 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/24 13:30:16 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(void *param)
{
	(void)param;
	ft_printf("GAME ABORT!!!");
	exit(0);
}

void	map_test(t_map map)
{
	check_walls(&map);
	check_elements(&map);
	test_path(&map);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_map	map_check;

	if (argc != 2)
	{
		ft_printf("Wait!! What? Where's the file?\n");
		exit(1);
	}
	map_check = get_map(argv[1]);
	map_test(map_check);
	gt_free(map_check.map);
	if (map.map == NULL)
	{
		print_error("Error: Could not read map from this file");
		exit(1);
	}
	map = get_map(argv[1]);
	check_elements(&map);
	so_long_init(&map);
	mlx_key_hook(map.mlx_init, &ft_key_hook, &map);
	mlx_close_hook(map.mlx_init, &exit_game, &map);
	draw_map(&map);
	gt_free(map.map);
	return (0);
}

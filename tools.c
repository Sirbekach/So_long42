/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:27:17 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/23 22:17:09 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

t_map	handle_error(void)
{
	t_map	map;

	map.map = NULL;
	map.coin = 0;
	map.play = 0;
	map.exit = 0;
	map.rows = 0;
	map.cols = 0;
	map.check_c = 0;
	map.check_e = 0;
	return (map);
}

void	ft_file_error(const char *s)
{
	print_error(s);
	exit(1);
}

void	ft_map_error(const char *s, char **map)
{
	print_error(s);
	gt_free(map);
	exit(1);
}

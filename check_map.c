/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:27:27 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/23 22:11:51 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_element(t_map **element)
{
	(*element)->play = 0;
	(*element)->coin = 0;
	(*element)->exit = 0;
	(*element)->check_c = 0;
	(*element)->check_e = 0;
	(*element)->movm = 0;
}

void	count_element(t_map *element)
{
	int		i;
	int		j;
	char	*str;

	set_element(&element);
	i = 0;
	while (i < element->rows)
	{
		str = element->map[i];
		j = 0;
		while (str[j])
		{
			if (str[j] == 'P')
				element->play++;
			else if (str[j] == 'C')
				element->coin++;
			else if (str[j] == 'E')
				element->exit++;
			j++;
		}
		i++;
	}
}

void	check_walls(t_map *m)
{
	int		i;
	int		j;

	i = 0;
	while (i < m->rows)
	{
		j = 0;
		while (m->map[i][j])
		{
			if (i == 0 || i == m->rows - 1)
			{
				if (m->map[i][j] != '1')
					ft_map_error("ERROR: invalid wall map", m->map);
			}
			else
			{
				if (m->map[i][0] != '1' 
					|| m->map[i][m->cols - 1] != '1')
					ft_map_error("ERROR: invalid wall map", m->map);
			}
			j++;
		}
		i++;
	}
}

static int	check_unkown(t_map *element)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (element->map[i])
	{
		j = 0;
		while (element->map[i][j])
		{
			if ((element->map[i][j] != 'C' && element->map[i][j] != '1'
				&& element->map[i][j] != '0' && element->map[i][j] != 'P'
				&& element->map[i][j] != 'E'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_elements(t_map *element)
{
	if (!check_unkown(element))
		ft_map_error("ERROR: Elements not known", element->map);
	count_element(element);
	if (element->play != 1)
		ft_map_error("ERROR: player invalid", element->map);
	if (element->exit != 1)
		ft_map_error("ERROR: exit invalid", element->map);
	if (element->coin < 1)
		ft_map_error("ERROR: coin invalid", element->map);
}

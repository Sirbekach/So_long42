/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:07:23 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/23 22:25:24 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_file(char *file)
{
	int		fd;

	if (!is_file_valid(file))
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_file_error("Tta fine rah file?");
	return (fd);
}

char	**read_map(int fd)
{
	char	*str;
	char	*line;
	char	*tmp;
	char	**map;

	str = ft_strdup(""); 
	line = get_next_line(fd);
	if (!line)
		ft_file_error("File is empty");
	while ((line))
	{
		if (line[0] == '\n')
			ft_file_error("Map is not well structred");
		tmp = str;
		str = gt_strjoin(str, line);
		str = gt_strjoin(str, "\n");
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(str, '\n');
	free(str);
	return (map);
}

static int	is_structured(char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			ft_map_error("map is not well structured", map);
		i++;
	}
	return (1);
}

static void	cal_dimensions(char **map, int *rows, int *max_cols)
{
	int	len;

	while (map[*rows])
	{
		len = ft_strlen(map[*rows]);
		if (len > *max_cols)
		{
			*max_cols = len;
		}
		(*rows)++;
	}
}

t_map	get_map(char *file)
{
	t_map	result;
	int		fd;
	char	**map;
	int		rows;
	int		max_cols;

	rows = 0;
	max_cols = 0;
	fd = get_file(file);
	if (fd == -1)
		return (handle_error());
	map = read_map(fd);
	if (map == NULL)
		return (handle_error());
	if (!is_structured(map))
		return (handle_error());
	cal_dimensions(map, &rows, &max_cols);
	result.map = map;
	result.rows = rows;
	result.cols = max_cols;
	close(fd);
	return (result);
}

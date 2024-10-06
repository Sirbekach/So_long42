/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:28:02 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/24 11:19:09 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include "/Users/ybekach/MLX42/include/MLX42/MLX42.h"

typedef struct s_map
{
	int				coin;
	int				play;
	int				exit;
	int				rows;
	int				cols;
	int				movm;
	char			**map;
	int				check_c;
	int				check_e;
	mlx_image_t		*player;
	void			*mlx_init;
}				t_map;

typedef struct s_player
{
	int	x;
	int	y;
}				t_player;

t_map		handle_error(void);
char		**read_map(int fd);
t_map		get_map(char *file);
void		draw_map(t_map *map);
void		test_path(t_map *map);
void		check_walls(t_map *m);
void		so_long_init(t_map *map);
int			is_file_valid(char *file);
void		print_error(const char *s);
void		ft_file_error(const char *s);
void		check_elements(t_map *element);
void		ft_map_error(const char *s, char **map);
void		ft_key_hook(mlx_key_data_t key, void *param);
mlx_image_t	*draw_element(t_map *map, int cols, int rows, char *path);

#endif
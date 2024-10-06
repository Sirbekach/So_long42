/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:49:43 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/23 22:08:37 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_error(void)
{
	print_error("File name is not valid");
	exit(1);
}

int	is_ber_valid(char *extension)
{
	int		is_ber;
	int		is_dot;
	int		is_end;

	if (ft_strlen(extension) != 4)
	{
		file_error();
		return (0);
	}
	is_dot = extension[0] == '.';
	is_ber = extension[1] == 'b' && extension[2] == 'e' && extension[3] == 'r';
	is_end = extension[4] == '\0';
	if (!(is_dot && is_ber && is_end))
		file_error();
	return (1);
}

int	is_file_valid(char *file)
{
	char	*sr;

	sr = ft_strrchr(file, '.');
	if (!sr)
		file_error();
	return (is_ber_valid(sr));
}

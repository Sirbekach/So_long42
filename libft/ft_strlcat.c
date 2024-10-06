/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:23:07 by ybekach           #+#    #+#             */
/*   Updated: 2024/01/16 10:53:46 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			is;
	unsigned int	i;
	unsigned int	id;
	unsigned int	j;

	i = 0;
	if (dst != NULL)
		id = ft_strlen(dst);
	else
		id = 0;
	is = ft_strlen(src);
	j = id;
	if (dstsize != 0 && id < dstsize)
	{
		while (src[i] != '\0' && id + i < dstsize - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = '\0';
	}
	if (id >= dstsize)
		id = dstsize;
	return (is + id);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:44:57 by ybekach           #+#    #+#             */
/*   Updated: 2023/12/19 09:50:03 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	i;
	size_t	strl;

	strl = ft_strlen(s1) + 1;
	new = (char *)malloc(sizeof(char) * strl);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < strl)
	{
		new[i] = s1[i];
		i++;
	}
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:22:46 by ybekach           #+#    #+#             */
/*   Updated: 2024/01/16 10:55:00 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	strl;
	char	*new;

	if (s == NULL)
		return (NULL);
	strl = ft_strlen(s);
	if (!s || start >= strl)
		return (ft_strdup(""));
	if (start + len > strl)
		len = strl - start;
	j = 0;
	i = start;
	new = (char *)malloc(len + 1);
	if (new == NULL)
		return (NULL);
	while (j < len && s[i] != '\0')
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

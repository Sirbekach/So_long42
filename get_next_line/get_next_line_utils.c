/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:52:58 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/19 15:26:14 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gt_strlen(const char *str)
{
	int		i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	gt_free(char **s)
{
	free(*s);
	*s = NULL;
}

char	*gt_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	lens1;
	size_t	lens2;
	char	*str;

	lens1 = gt_strlen(s1);
	lens2 = gt_strlen(s2);
	str = malloc(lens1 + lens2 + 1);
	if (str == NULL)
		return (gt_free(&s1), NULL);
	i = 0;
	while (s1 && i < lens1)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && j < lens2)
		str[i++] = s2[j++];
	str[i] = '\0';
	gt_free(&s1);
	return (str);
}

int	gt_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if ((char)s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:32:21 by ybekach           #+#    #+#             */
/*   Updated: 2024/01/11 14:49:54 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s[i] != c && s[i] != '\0')
	{
		i++;
		count++;
	}
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static	void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	**fill_word(char **word, char const *s, char c, int n)
{
	int		i;
	int		start;
	int		rows;

	i = 0;
	rows = 0;
	while (rows < n)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		word[rows] = ft_substr(s, start, i - start);
		if (!word[rows])
		{
			ft_free(word);
			return (NULL);
		}
		rows++;
	}
	word[rows] = NULL;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**word;
	int		count;

	if (s == NULL)
		return (NULL);
	count = count_word(s, c);
	word = (char **)malloc(sizeof(char *) * (count + 1));
	if (word == NULL)
		return (NULL);
	word = fill_word(word, s, c, count);
	if (word == NULL)
		return (NULL);
	return (word);
}

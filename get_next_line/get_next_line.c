/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:46:39 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/19 15:25:57 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *text)
{
	int		r;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	{
		gt_free(&text);
		return (NULL);
	}
	r = 1;
	while (r != 0 && !gt_strchr(text, '\n'))
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 0)
		{
			gt_free(&text);
			gt_free(&buffer);
			return (NULL);
		}
		buffer[r] = '\0';
		text = gt_strjoin(text, buffer);
	}
	free(buffer);
	return (text);
}

char	*edit_line(char	*str)
{
	int		i;
	int		size;
	char	*text;

	i = 0;
	size = 0;
	while ((str[size] != '\0') && (str[size] != '\n'))
		size++;
	size = size + (str[size] == '\n');
	text = malloc(size + 1);
	if (text == NULL)
		return (NULL);
	while (str[i] != '\0' && i < size)
	{
		text[i] = str[i];
		i++;
	}
	text[i] = '\0';
	return (text);
}

char	*extract_rest(char *str)
{
	int		i;
	int		len;
	int		size;
	char	*text;

	len = gt_strlen(str);
	i = 0;
	size = 0;
	while (str[size] != '\0' && str[size] != '\n')
		size++;
	text = malloc((len - size) + 1);
	if (text == NULL)
	{
		gt_free(&str);
		return (NULL);
	}
	while (str[size++] != '\0')
		text[i++] = str[size];
	text[i] = '\0';
	free(str);
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*output_text; 

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		gt_free(&text);
		return (NULL);
	}
	text = read_line(fd, text);
	if (text == NULL || text[0] == '\0')
	{
		gt_free(&text);
		return (NULL);
	}
	output_text = edit_line(text);
	if (output_text == NULL || output_text[0] == '\0')
	{
		gt_free(&text);
		return (NULL);
	}
	text = extract_rest(text);
	return (output_text);
}

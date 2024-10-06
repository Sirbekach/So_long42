/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:55:33 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/19 15:25:12 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	gt_strlen(const char *str);
void	gt_free(char **s);
char	*gt_strjoin(char *s1, char *s2);
int		gt_strchr(const char *s, int c);
char	*read_line(int fd, char *text);
char	*edit_line(char *str);
char	*extract_rest(char *str);
char	*get_next_line(int fd);

#endif
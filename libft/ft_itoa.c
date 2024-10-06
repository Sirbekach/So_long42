/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:08:56 by ybekach           #+#    #+#             */
/*   Updated: 2024/01/08 09:46:01 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digit(int n)
{
	int		i;
	int		q;

	q = n;
	i = 0;
	if (n == 0)
		return (1);
	while (q != 0)
	{
		q = q / 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	long	q;
	int		index;
	char	*number;
	int		len;

	len = count_digit(n);
	index = len - 1;
	number = (char *)malloc(sizeof(char) * (len + 1));
	if (number == NULL)
		return (NULL);
	q = n;
	number[index + 1] = '\0';
	if (n < 0)
	{
		number[0] = '-';
		q = -q;
	}
	while (q != 0)
	{
		number[index--] = (q % 10) + '0';
		q = q / 10;
	}
	if (index == len - 1)
		number[index] = '0';
	return (number);
}

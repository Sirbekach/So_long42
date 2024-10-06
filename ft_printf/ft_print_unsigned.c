/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:22:39 by ybekach           #+#    #+#             */
/*   Updated: 2024/01/21 12:36:57 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int		q;
	int		counter;

	counter = 0;
	if (n >= 10)
	{
		counter += ft_print_unsigned(n / 10);
		counter += ft_print_unsigned(n % 10);
	}
	else if (n < 10)
	{
		q = n + 48;
		counter += write(1, &q, 1);
	}
	return (counter);
}

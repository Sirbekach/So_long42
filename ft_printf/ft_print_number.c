/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:13:15 by ybekach           #+#    #+#             */
/*   Updated: 2024/01/21 12:16:45 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_number(int n)
{
	char	q;
	int		counter;

	counter = 0;
	if (n == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	else if (n < 0)
	{
		n = -n;
		counter += write(1, "-", 1);
		counter += ft_print_number(n);
	}
	else if (n >= 10)
	{
		counter += ft_print_number(n / 10);
		counter += ft_print_number(n % 10);
	}
	else if (n < 10)
	{
		q = n + 48;
		counter += write(1, &q, 1);
	}
	return (counter);
}

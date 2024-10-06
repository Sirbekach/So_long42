/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:18:25 by ybekach           #+#    #+#             */
/*   Updated: 2024/01/21 12:57:05 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int n, char type)
{
	int		counter;

	counter = 0;
	if (n > 15)
	{
		counter += ft_print_hexa(n / 16, type);
		counter += ft_print_hexa(n % 16, type);
	}
	else if (n <= 15)
	{
		if (type == 'X')
			counter += ft_print_char("0123456789ABCDEF"[n]);
		else if (type == 'x')
			counter += ft_print_char("0123456789abcdef"[n]);
	}
	return (counter);
}

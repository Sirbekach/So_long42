/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:54:36 by ybekach           #+#    #+#             */
/*   Updated: 2024/01/21 17:36:00 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexa(unsigned long n)
{
	unsigned long	q;
	int				counter;

	counter = 0;
	q = (unsigned long) n;
	if (q > 15)
	{
		counter += ft_put_hexa(q / 16);
		counter += ft_put_hexa(q % 16);
	}
	else if (q <= 15)
	{
		counter += ft_print_char("0123456789abcdef"[q]);
	}
	return (counter);
}

int	ft_print_address(void *p)
{
	unsigned long	q;
	int				counter;

	counter = 0;
	counter += write(1, &"0x", 2);
	q = (unsigned long) p;
	counter += ft_put_hexa(q);
	return (counter);
}

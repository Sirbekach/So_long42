/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:01:40 by ybekach           #+#    #+#             */
/*   Updated: 2024/01/22 10:42:44 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(void)
{
	return (write(1, "%", 1));
}

int	ft_check_and_print(char type, va_list lst)
{
	int	counter;

	counter = 0;
	if (type == 'c')
		counter += ft_print_char(va_arg(lst, int));
	else if (type == 'd' || type == 'i')
		counter += ft_print_number(va_arg(lst, int));
	else if (type == 's')
		counter += ft_print_string(va_arg(lst, char *));
	else if (type == 'u')
		counter += ft_print_unsigned(va_arg(lst, unsigned int));
	else if (type == 'X' || type == 'x')
		counter += ft_print_hexa(va_arg(lst, unsigned long), type);
	else if (type == 'p')
		counter += ft_print_address(va_arg(lst, void *));
	else if (type == '%')
		counter += ft_print_percent();
	else
		counter += write(1, &type, 1);
	return (counter);
}

int	ft_printf(const char *s, ...)
{
	va_list	lst;
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	if ((write(1, 0, 0)) == -1)
		return (-1);
	va_start(lst, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			if (s[i + 1] != '\0')
			{
				counter += ft_check_and_print(s[i + 1], lst);
				i++;
			}
		}
		else
			counter += ft_print_char(s[i]);
		i++;
	}
	va_end(lst);
	return (counter);
}

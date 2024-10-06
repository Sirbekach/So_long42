/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:12:06 by ybekach           #+#    #+#             */
/*   Updated: 2024/01/21 12:54:41 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_print_char(char c);
int	ft_print_string(char *c);
int	ft_print_address(void *p);
int	ft_print_number(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hexa(unsigned int n, char type);
int	ft_printf(const char *s, ...);

#endif

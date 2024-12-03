/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:40:19 by qupollet          #+#    #+#             */
/*   Updated: 2024/12/03 00:48:56 by NekoTintin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_selectformat(char format, va_list arg_list)
{
	if (format == '%')
		return (ft_putchar_fd('%', 1));
	else if (format == 'c')
		return (ft_putchar_fd(va_arg(arg_list, int), 1));
	else if (format == 's')
		return (ft_putstr_fd(va_arg(arg_list, char *), 1));
	else if (format == 'i' || format == 'd')
		return (ft_print_nbr(va_arg(arg_list, int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hexa(va_arg(arg_list, int), format));
	else if (format == 'u')
		return (ft_print_udecimal(va_arg(arg_list, unsigned int)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(arg_list, void *)));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list			arg_list;
	int				idx;
	unsigned int	nb_char;

	if (str == NULL)
		return (-1);
	va_start(arg_list, str);
	idx = 0;
	nb_char = 0;
	while (str[idx] != 0)
	{
		if (str[idx] == '%')
		{
			if (str[idx + 1] == 0)
				return (va_end(arg_list), -1);
			nb_char += ft_selectformat(str[idx + 1], arg_list);
			idx++;
		}
		else
			nb_char += ft_putchar_fd(str[idx], 1);
		idx++;
	}
	va_end(arg_list);
	return (nb_char);
}

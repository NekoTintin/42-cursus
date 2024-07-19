/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:46:22 by qupollet          #+#    #+#             */
/*   Updated: 2024/06/24 16:05:27 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_ptr_len(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

int	ft_print_ptr(const void *ptr)
{
	uintptr_t	addr;
	char		*res;
	char		*char_set;
	int			idx;
	int			count;

	count = 0;
	addr = (uintptr_t)ptr;
	if (addr == 0)
		return (ft_putstr_fd("(nil)", 1));
	idx = ft_get_ptr_len(addr);
	res = (char *)ft_calloc(idx + 3, sizeof(char));
	if (!res)
		return (0);
	char_set = "0123456789abcdef";
	while (addr != 0)
	{
		res[--idx] = char_set[addr % 16];
		addr /= 16;
		count++;
	}
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(res + idx, 1);
	free(res);
	return (count + 2);
}

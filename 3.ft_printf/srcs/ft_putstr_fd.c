/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:58:39 by qupollet          #+#    #+#             */
/*   Updated: 2024/12/03 00:50:33 by NekoTintin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	index;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	index = -1;
	if (s)
		while (s[++index])
			ft_putchar_fd(s[index], fd);
	return (index);
}

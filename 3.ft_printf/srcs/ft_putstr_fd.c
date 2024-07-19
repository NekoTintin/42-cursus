/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:58:39 by qupollet          #+#    #+#             */
/*   Updated: 2024/06/24 15:38:39 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

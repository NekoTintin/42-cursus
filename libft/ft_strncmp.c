/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <quentinpollet27@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:53:19 by qupollet          #+#    #+#             */
/*   Updated: 2024/05/28 12:32:38 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;

	idx = 0;
	if (n == 0)
		return (0);
	while ((s1[idx] || s2[idx]) && (s1[idx] == s2[idx]) && idx < n - 1)
		idx++;
	return ((unsigned char) s1[idx] - (unsigned char)s2[idx]);
}

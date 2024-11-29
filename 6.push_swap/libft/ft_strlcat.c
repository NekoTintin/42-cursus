/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:19:27 by qupollet          #+#    #+#             */
/*   Updated: 2024/06/04 14:26:35 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	d_len;
	size_t	s_len;
	size_t	idx;

	if (siz > 0)
	{
		s_len = ft_strlen(src);
		d_len = ft_strlen(dst);
		if (siz <= d_len)
			return (siz + s_len);
		idx = 0;
		while (d_len + idx < siz - 1 && src[idx])
		{
			dst[d_len + idx] = src[idx];
			idx++;
		}
		dst[d_len + idx] = '\0';
		return (s_len + d_len);
	}
	return (ft_strlen(src));
}

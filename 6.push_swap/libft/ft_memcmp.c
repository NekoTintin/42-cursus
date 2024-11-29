/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <quentinpollet27@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:57:56 by qupollet          #+#    #+#             */
/*   Updated: 2024/05/23 15:45:04 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			idx;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	idx = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (idx < n)
	{
		if (ptr1[idx] != ptr2[idx])
			return (ptr1[idx] - ptr2[idx]);
		idx++;
	}
	return (0);
}

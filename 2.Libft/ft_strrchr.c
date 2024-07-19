/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <quentinpollet27@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:30:24 by qupollet          #+#    #+#             */
/*   Updated: 2024/05/31 16:25:37 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	str_size;
	int	idx;

	str_size = ft_strlen(s);
	idx = str_size - 1;
	if ((unsigned char)c == 0)
		return ((char *)&s[str_size]);
	while (idx >= 0)
	{
		if (s[idx] == (unsigned char)c)
			return ((char *)&s[idx]);
		idx--;
	}
	return (NULL);
}

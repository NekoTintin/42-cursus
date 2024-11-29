/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <quentinpollet27@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:24:06 by qupollet          #+#    #+#             */
/*   Updated: 2024/05/31 16:24:45 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	idx;

	idx = -1;
	while (s[++idx])
	{
		if (s[idx] == (unsigned char)c)
			return ((char *)&s[idx]);
	}
	if ((unsigned char)c == 0 && s[idx] == 0)
		return ((char *)&s[idx]);
	return ((char *) NULL);
}

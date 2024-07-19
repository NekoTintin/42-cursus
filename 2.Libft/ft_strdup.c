/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <quentinpollet27@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:53:19 by qupollet          #+#    #+#             */
/*   Updated: 2024/05/30 13:20:32 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	idx;
	size_t	len;
	char	*nstr;

	idx = 0;
	len = ft_strlen(s);
	nstr = malloc(sizeof(char) * (len + 1));
	if (!nstr)
		return (NULL);
	while (idx < len && s[idx])
	{
		nstr[idx] = s[idx];
		idx++;
	}
	nstr[idx] = 0;
	return (nstr);
}

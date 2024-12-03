/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:53:19 by qupollet          #+#    #+#             */
/*   Updated: 2024/12/03 00:50:37 by NekoTintin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

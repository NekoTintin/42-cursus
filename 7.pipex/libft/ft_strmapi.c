/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <quentinpollet27@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:45:29 by qupollet          #+#    #+#             */
/*   Updated: 2024/05/31 11:09:16 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		idx;
	char				*nstr;

	if (!s || !f)
		return (NULL);
	idx = 0;
	nstr = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!nstr)
		return (NULL);
	while (s[idx] != 0)
	{
		nstr[idx] = f(idx, s[idx]);
		idx++;
	}
	nstr[idx] = 0;
	return (nstr);
}

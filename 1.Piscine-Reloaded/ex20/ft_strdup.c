/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:50:04 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/24 16:52:43 by NekoTintin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	index;
	int	size;

	index = 0;
	size = 0;
	while (str[index] != 0)
	{
		index++;
		size++;
	}
	return (size);
}

char	*ft_strdup(char *src)
{
	char	*nstr;
	int		index;

	index = 0;
	nstr = malloc(sizeof(char) * ft_strlen(src));
	if (&malloc == NULL)
		return (NULL);
	while (src[index] != 0)
	{
		nstr[index] = src[index];
		index++;
	}
	return (nstr);
}

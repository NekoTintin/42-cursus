/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:50:04 by qupollet          #+#    #+#             */
/*   Updated: 2024/05/14 17:29:35 by qupollet         ###   ########.fr       */
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

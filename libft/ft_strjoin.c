/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <quentinpollet27@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:49:43 by qupollet          #+#    #+#             */
/*   Updated: 2024/05/31 11:02:22 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n_str;
	int		index1;
	int		index2;

	if (!s1 || !s2)
		return (NULL);
	index1 = -1;
	index2 = -1;
	n_str = malloc((sizeof(char) * ft_strlen(s1))
			+ ((sizeof(char) * ft_strlen(s2))) + 1);
	if (!n_str)
		return (NULL);
	while (s1[++index1] != 0)
		n_str[index1] = s1[index1];
	while (s2[++index2] != 0)
		n_str[index1 + index2] = s2[index2];
	n_str[index1 + index2] = 0;
	return (n_str);
}

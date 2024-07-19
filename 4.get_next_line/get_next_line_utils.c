/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:34:39 by qupollet          #+#    #+#             */
/*   Updated: 2024/07/08 14:46:57 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*nstr;
	size_t	s_idx;
	size_t	nstr_idx;

	if (s)
	{
		if (start > (unsigned int)ft_strlen(s))
			return (ft_strdup(""));
		s_idx = start;
		nstr_idx = 0;
		if (len > (size_t)ft_strlen(s + start))
			len = (size_t)ft_strlen(s + start);
		nstr = malloc(sizeof(char) * len + 1);
		if (!nstr)
			return (NULL);
		while (s[s_idx] && nstr_idx < len)
		{
			nstr[nstr_idx] = s[s_idx];
			nstr_idx++;
			s_idx++;
		}
		nstr[nstr_idx] = 0;
		return (nstr);
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	int	idx;

	idx = -1;
	if (!s)
		return (NULL);
	while (s[++idx])
	{
		if (s[idx] == (unsigned char)c)
			return ((char *)&s[idx]);
	}
	if ((unsigned char)c == 0 && s[idx] == 0)
		return ((char *)&s[idx]);
	return (NULL);
}

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

int	ft_strlen(const char *s)
{
	int	lenght;
	int	index;

	lenght = 0;
	index = -1;
	while (s[++index] != '\0')
		lenght++;
	return (lenght);
}

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

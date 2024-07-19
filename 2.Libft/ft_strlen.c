/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <quentinpollet27@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:26:29 by qupollet          #+#    #+#             */
/*   Updated: 2024/05/17 12:41:41 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

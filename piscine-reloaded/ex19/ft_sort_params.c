/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <quentinpollet27@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:46:20 by qupollet          #+#    #+#             */
/*   Updated: 2024/05/16 18:06:24 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_str_tab(char **tab, int size)
{
	int		i;
	int		y;
	char	*temp;

	i = 0;
	y = 0;
	while (i < size)
	{
		while (y < size - 1)
		{
			if (ft_strcmp(tab[y], tab[y + 1]) > 0)
			{
				temp = tab[y];
			tab[y] = tab[y + 1];
				tab[y + 1] = temp;
			}
			y++;
		}
		y = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc <= 1)
		return (1);
	ft_sort_str_tab(argv + 1, argc - 1);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}

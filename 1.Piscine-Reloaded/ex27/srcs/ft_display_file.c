/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <quentinpollet27@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:30:44 by qupollet          #+#    #+#             */
/*   Updated: 2024/05/17 14:34:12 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		write(2, &c, 1);
		i++;
	}
}

int	ft_display_file(char *path)
{
	int		file;
	int		size;
	char	buf[10];

	file = open(path, O_RDONLY);
	if (file < 0)
		return (1);
	size = read(file, buf, 10);
	while (size)
	{
		if (size == -1)
		{
			close(file);
			return (1);
		}
		write(1, buf, size);
		size = read(file, buf, 10);
	}
	close(file);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr("File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (1);
	}
	if (ft_display_file(argv[1]))
	{
		ft_putstr("Cannot read file.\n");
		return (1);
	}
	return (0);
}

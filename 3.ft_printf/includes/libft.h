/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:07:06 by qupollet          #+#    #+#             */
/*   Updated: 2024/06/21 16:42:25 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *s);
char	*ft_strdup(const char *c);

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);

#endif
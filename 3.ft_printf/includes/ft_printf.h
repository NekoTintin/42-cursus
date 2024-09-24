/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NekoTintin <tintin361official@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:27:52 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/24 16:56:20 by NekoTintin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);

int		ft_print_hexa(unsigned int nbr, char state);
int		ft_print_udecimal(unsigned int nbr);
int		ft_print_ptr(const void *ptr);
int		ft_print_nbr(int n);

#endif
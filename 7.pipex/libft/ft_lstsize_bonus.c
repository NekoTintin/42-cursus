/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qupollet <qupollet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:56:14 by qupollet          #+#    #+#             */
/*   Updated: 2024/09/07 14:00:51 by qupollet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*nptr;
	int		counter;

	counter = 0;
	nptr = lst;
	while (nptr)
	{
		counter++;
		nptr = nptr->next;
	}
	return (counter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:23:23 by dbendu            #+#    #+#             */
/*   Updated: 2019/10/09 16:57:37 by ymanilow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dlstsize(const t_dlist *list)
{
	size_t size;

	size = 0;
	while (list)
	{
		++size;
		list = list->next;
	}
	return (size);
}

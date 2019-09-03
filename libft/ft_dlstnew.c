/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:23:11 by dbendu            #+#    #+#             */
/*   Updated: 2019/06/26 18:23:12 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(const void *data, size_t size)
{
	t_dlist *new;

	if (!data || !size)
		return (NULL);
	if (!(new = malloc(sizeof(t_dlist))))
		return (NULL);
	if (!(new->data = malloc(size)))
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(new->data, data, size);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:15:59 by dbendu            #+#    #+#             */
/*   Updated: 2019/04/08 20:50:32 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem))
{
	t_list			*new_list;
	register t_list	*iter;

	if (!list || !f)
		return (NULL);
	new_list = f(list);
	if (!new_list)
		return (NULL);
	iter = new_list;
	list = list->next;
	while (list)
	{
		if (!(iter->next = f(list)))
		{
			ft_lstremove(&new_list);
			return (NULL);
		}
		iter = iter->next;
		list = list->next;
	}
	return (new_list);
}

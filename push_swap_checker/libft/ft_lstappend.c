/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:49:20 by dbendu            #+#    #+#             */
/*   Updated: 2019/04/18 16:49:21 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **list, t_list *new)
{
	if (!list || !new)
		return ;
	if (!*list)
	{
		*list = new;
		new->end = new;
	}
	else
	{
		(*list)->end->next = new;
		(*list)->end = new;
	}
}

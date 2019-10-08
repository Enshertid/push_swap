/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrnchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 21:32:07 by user              #+#    #+#             */
/*   Updated: 2019/09/15 15:05:24 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrnchr(const void *memptr, int val, size_t num)
{
	register unsigned char *str;

	str = (unsigned char*)memptr;
	while (num)
	{
		if (*str != (unsigned char)val)
			return (str);
		--str;
		--num;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:09:25 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:09:25 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

void	*ft_memcpy(void *dst, const void *src, int size)
{
	void	*beg;

	beg = dst;
	while (size-- > 0)
		*(uint8_t *)dst++ = *(uint8_t *)src++;
	return (beg);
}

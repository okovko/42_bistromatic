/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:09:58 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:09:58 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

void	*ft_memset(void *mem, int set, int size)
{
	uint8_t	*bytes;

	bytes = mem;
	while (size-- > 0)
		*bytes++ = (uint8_t)set;
	return (mem);
}

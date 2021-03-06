/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:10:31 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:10:31 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"

void						ft_ptrswap(void **aa, void **bb)
{
	void					*tmp;

	tmp = *aa;
	*aa = *bb;
	*bb = tmp;
}

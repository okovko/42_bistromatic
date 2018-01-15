/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countable_nbr_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:13:32 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:13:32 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include "ft_countable_nbr.h"

t_countable_nbr				*countable_nbr_add
							(t_countable_nbr *lhs, t_countable_nbr *rhs)
{
	t_countable_nbr			*nbr;
	int						carry;
	int						rem;
	int						ii;

	if (lhs->size < rhs->size)
		ft_ptrswap((void **)&lhs, (void **)&rhs);
	nbr = new_countable_nbr(lhs->base, lhs->sign, lhs->size + 1);
	nbr->digits = ft_memcpy(nbr->digits, lhs->digits, lhs->size);
	ii = 0;
	while (ii < rhs->size)
	{
		if (lhs->sign == rhs->sign)
		{
			nbr->digits[ii] += rhs->digits[ii];
			carry = nbr->digits[ii] >= nbr->base;
			rem = nbr->digits[ii] - nbr->base;
			nbr->digits[ii] = rem;
			nbr->digits[ii + 1] += carry;
		}
		else
			nbr->digits[ii] -= rhs->digits[ii];
		ii++;
	}
	return (nbr);
}

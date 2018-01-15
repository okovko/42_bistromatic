/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countable_nbr_mul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:13:57 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:13:57 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include "ft_countable_nbr.h"

t_countable_nbr				*countable_nbr_mul
							(t_countable_nbr *lhs, t_countable_nbr *rhs)
{
	t_countable_nbr			*nbr;
	int						ii;
	int						jj;
	int						div;
	int						rem;

	if (lhs->size < rhs->size)
		ft_ptrswap((void **)&lhs, (void **)&rhs);
	nbr = new_countable_nbr(lhs->base, lhs->sign * rhs->sign, lhs->size + rhs->size);
	ii = 0;
	while (ii < lhs->size)
	{
		jj = 0;
		while (jj < rhs->size)
		{
			nbr->digits[ii + jj] += lhs->digits[ii] * rhs->digits[jj];
			div = nbr->digits[ii] / nbr->base;
			rem = nbr->digits[ii] - nbr->base * div;
			nbr->digits[ii] = rem;
			nbr->digits[ii + 1] += div;
			jj++;
		}
		ii++;
	}
	return (nbr);
}

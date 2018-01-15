/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countable_nbr_distrib_inc_or_dec.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:11:56 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:11:56 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include "ft_countable_nbr.h"

t_countable_nbr				*countable_nbr_distrib_inc_or_dec(t_countable_nbr *nbr)
{
	int						ii;
	int						carry;
	int						rem;

	ii = 0;
	while (ii < nbr->size && nbr->digits[ii] >= nbr->base)
	{
		carry = nbr->digits[ii] >= nbr->base;
		rem = nbr->digits[ii] - nbr->base;
		nbr->digits[ii + 1] += carry;
		nbr->digits[ii] = rem;
		ii++;
	}
	return (nbr);
}

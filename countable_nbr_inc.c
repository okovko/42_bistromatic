/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countable_nbr_inc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:12:14 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:12:14 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include "ft_countable_nbr.h"

t_countable_nbr				*countable_nbr_inc(t_countable_nbr *nbr)
{
	if (1 == nbr->sign)
		nbr->digits[0]++;
	else
		nbr->digits[0]--;
	countable_nbr_distrib_inc_or_dec(nbr);
	return (nbr);
}

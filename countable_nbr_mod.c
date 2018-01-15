/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countable_nbr_mod.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:14:41 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:14:41 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include "ft_countable_nbr.h"

t_countable_nbr				*countable_nbr_mod
							(t_countable_nbr *lhs, t_countable_nbr *rhs)
{
	t_countable_nbr			*nbr;
	t_countable_nbr			*product;
	t_countable_nbr			*sub;

	nbr = new_countable_nbr(lhs->base, 1, lhs->size);
	product = countable_nbr_mul(nbr, rhs);
	while (1 == countable_nbr_lte(product, lhs))
	{
		countable_nbr_inc(nbr);
		free_countable_nbr(&product);
		product = countable_nbr_mul(nbr, rhs);
	}
	sub = countable_nbr_sub(lhs, product);
	free_countable_nbr(&nbr);
	free_countable_nbr(&product);
	return (sub);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countable_nbr_lte.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:12:43 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:12:43 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include "ft_countable_nbr.h"

int							countable_nbr_lte
							(t_countable_nbr *lhs, t_countable_nbr *rhs)
{
	int						ii;
	int						left;
	int						right;

	if (1 == lhs->sign && -1 == rhs->sign)
		return (0);
	if (-1 == lhs->sign && 1 == rhs->sign)
		return (1);
	ii = lhs->size > rhs->size ? lhs->size - 1 : rhs->size - 1;
	while (ii >= 0)
	{
		left = ii < lhs->size ? lhs->digits[ii] : 0;
		right = ii < rhs->size ? rhs->digits[ii] : 0;
		if (left == right)
		{
			ii--;
			continue ;
		}
		if (1 == lhs->sign && 1 == rhs->sign)
			return (left < right);
		if (-1 == lhs->sign && -1 == rhs->sign)
			return (left > right);
		ii--;
	}
	return (1);
}

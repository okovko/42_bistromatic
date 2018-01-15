/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countable_nbr_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:13:47 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:13:47 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include "ft_countable_nbr.h"

t_countable_nbr				*countable_nbr_sub
							(t_countable_nbr *lhs, t_countable_nbr *rhs)
{
	rhs->sign = !rhs->sign;
	return (countable_nbr_add(lhs, rhs));
}

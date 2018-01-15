/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countable_nbr_gte.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:13:15 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:13:15 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include "ft_countable_nbr.h"

int							countable_nbr_gte
							(t_countable_nbr *lhs, t_countable_nbr *rhs)
{
	return (0 == countable_nbr_lte(lhs, rhs));
}

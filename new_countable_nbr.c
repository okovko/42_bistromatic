/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_countable_nbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:11:04 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:11:04 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include "ft_countable_nbr.h"

t_countable_nbr				*new_countable_nbr(int base, int sign, int size)
{
	t_countable_nbr			*new_nbr;

	new_nbr = malloc(sizeof(*new_nbr));
	new_nbr->base = base;
	new_nbr->sign = sign;
	new_nbr->size = size;
	new_nbr->digits = malloc(size);
	ft_memset(new_nbr->digits, 0, size);
	return (new_nbr);
}

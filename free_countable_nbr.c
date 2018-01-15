/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_countable_nbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:11:33 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:11:33 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include "ft_countable_nbr.h"

void						free_countable_nbr(t_countable_nbr **nbr)
{
	t_countable_nbr			*tmp;

	tmp = *nbr;
	free(tmp->digits);
	free(tmp);
	*nbr = NULL;
}

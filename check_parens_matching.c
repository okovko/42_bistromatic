/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parens_matching.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:14:54 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:14:54 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include "ft_countable_nbr.h"

int							check_parens_matching(char *input, int size)
{
	int						ii;

	ii = 0;
	while ('\0' != input[ii] && ii < size)
	{
		if (')' == input[ii])
			return (0);
		if ('(' == input[ii])
			return (0 == check_parens_matching(input + ii, size - ii));
		ii++;
	}
	return (1);
}

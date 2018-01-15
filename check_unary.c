/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:16:01 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:16:01 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include "ft_countable_nbr.h"

int							check_unary(char *digits, char *input, int pos, int size)
{
	if (pos < size && ISOP_SUM(input[pos]))
	{
		pos++;
		if (check_unary(digits, input, pos, size))
			return (1);
		if (check_num(digits, input, pos, size))
			return (1);
		if (check_open(digits, input, pos, size))
			return (1);
	}
	return (0);
}

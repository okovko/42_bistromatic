/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:15:48 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:15:48 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include "ft_countable_nbr.h"

int							check_binary(char *digits, char *input, int pos, int size)
{
	if (pos < size && ISOP(input[pos]))
	{
		pos++;
		if (check_num(digits, input, pos, size))
			return (1);
		if (check_open(digits, input, pos, size))
			return (1);
	}
	return (0);
}

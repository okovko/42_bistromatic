/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:15:34 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:15:34 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include "ft_countable_nbr.h"

int							check_num(char *digits, char *input, int pos, int size)
{
	int						any;

	if (pos >= size)
		return (0);
	any = 0;
	while ('\0' != *digits)
	{
		any = input[pos] == *digits;
		if (1 == any)
			break;
		digits++;
	}
	if (1 == any)
	{
		pos++;
		if (check_num(digits, input, pos, size))
			return (1);
		if (check_binary(digits, input, pos, size))
			return (1);
		if (check_close(digits, input, pos, size))
			return (1);
		if (check_end(digits, input, pos, size))
			return (1);
	}
	return (0);
}

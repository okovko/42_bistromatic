/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:15:15 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:15:15 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include "ft_countable_nbr.h"

int							check_close(char *digits, char *input, int pos, int size)
{
	if (pos < size && ')' == input[pos])
	{
		pos++;
		if (check_binary(digits, input, pos, size))
			return (1);
		if (check_end(digits, input, pos, size))
			return (1);
	}
	return (0);
}

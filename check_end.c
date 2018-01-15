/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:15:05 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:15:05 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include "ft_countable_nbr.h"

int							check_end(char *digits, char *input, int pos, int size)
{
	(void)digits;
	if ('\0' == input[pos] || pos == size - 1)
		return (1);
	return (0);
}

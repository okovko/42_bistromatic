/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:16:10 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:16:10 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatic.h"
#include "ft_countable_nbr.h"

int							grammar(char *digits, char *input, int size)
{
	if (1 != check_parens_matching(input, size))
		return (0);
	if (check_unary(digits, input, 0, size))
		return (1);
	if (check_num(digits, input, 0, size))
		return (1);
	if (check_open(digits, input, 0, size))
		return (1);
	if (check_end(digits, input, 0, size))
		return (1);
	return (0);
}

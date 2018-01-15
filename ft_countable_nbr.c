/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countable_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovaluee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:44:38 by olkovaluee          #+#    #+#             */
/*   Updated: 2018/01/15 01:44:44 by olkovaluee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "ft_countable_nbr.h"
#include "bistromatic.h"

int							main(int ac, char **av)
{
	t_countable_nbr			*lhs;
	t_countable_nbr			*rhs;
	t_countable_nbr			*res;
	int						ii;

	if (3 != ac)
		return (0);
	lhs = new_countable_nbr(10, 1, 2);
	ii = 0;
	while (ii < lhs->size)
	{
		lhs->digits[lhs->size - ii - 1] = av[1][ii] - '0';
		ii++;
	}
	rhs = new_countable_nbr(10, 1, 1);
	ii = 0;
	while (ii < rhs->size)
	{
		rhs->digits[rhs->size - ii - 1] = av[2][ii] - '0';
		ii++;
	}
	res = countable_nbr_div(lhs, rhs);
	printf("result: ");
	ii = res->size;
	while (ii >= 0)
	{
		if (res->digits[ii] == 0 && ii != 0)
		{
			ii--;
			continue ;
		}
		printf("%c", res->digits[ii] + '0');
		ii--;
	}
	printf("\n");
	/*
	free_countable_nbr(&lhs);
	free_countable_nbr(&rhs);
	free_countable_nbr(&res);
	*/
	return (0);
}

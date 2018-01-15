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

#define ABS(x) ((x) < 0 ? -(x) : (x))

void	*ft_memcpy(void *dst, const void *src, int size)
{
	void	*beg;

	beg = dst;
	while (size-- > 0)
		*(uint8_t *)dst++ = *(uint8_t *)src++;
	return (beg);
}

void	*ft_memset(void *mem, int set, int size)
{
	uint8_t	*bytes;

	bytes = mem;
	while (size-- > 0)
		*bytes++ = (uint8_t)set;
	return (mem);
}

int		ft_nbrlen(int value)
{
	int		size;

	size = value <= 0;
	while (value)
	{
		size++;
		value /= 10;
	}
	return (size);
}

char	*set_digits(int value, char *digits, int base)
{
	int		size;
	int		tmp;

	size = ft_nbrlen(value);
	if (value < 0)
		digits[0] = '-';
	if (value == 0)
		digits[0] = '0';
	digits[size] = '\0';
	size--;
	tmp = value;
	while (tmp)
	{
		digits[size] = '0' + ABS(tmp % base);
		tmp /= base;
		size--;
	}
	return (digits);
}

void						ptr_swap(void **aa, void **bb)
{
	void					*tmp;

	tmp = *aa;
	*aa = *bb;
	*bb = tmp;
}

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

void						free_countable_nbr(t_countable_nbr **nbr)
{
	t_countable_nbr			*tmp;

	tmp = *nbr;
	free(tmp->digits);
	free(tmp);
	*nbr = NULL;
}

t_countable_nbr				*countable_nbr_distrib_inc_or_dec(t_countable_nbr *nbr)
{
	int						ii;
	int						carry;
	int						rem;

	ii = 0;
	while (ii < nbr->size && nbr->digits[ii] >= nbr->base)
	{
		carry = nbr->digits[ii] >= nbr->base;
		rem = nbr->digits[ii] - nbr->base;
		nbr->digits[ii + 1] += carry;
		nbr->digits[ii] = rem;
		ii++;
	}
	return (nbr);
}

t_countable_nbr				*countable_nbr_inc(t_countable_nbr *nbr)
{
	if (1 == nbr->sign)
		nbr->digits[0]++;
	else
		nbr->digits[0]--;
	countable_nbr_distrib_inc_or_dec(nbr);
	return (nbr);
}

t_countable_nbr				*countable_nbr_dec(t_countable_nbr *nbr)
{
	if (-1 == nbr->sign)
		nbr->digits[0]++;
	else
		nbr->digits[0]--;
	countable_nbr_distrib_inc_or_dec(nbr);
	return (nbr);
}

int							countable_nbr_lte(t_countable_nbr *lhs, t_countable_nbr *rhs)
{
	int						ii;
	int						left;
	int						right;

	if (1 == lhs->sign && -1 == rhs->sign)
		return (0);
	if (-1 == lhs->sign && 1 == rhs->sign)
		return (1);
	ii = lhs->size > rhs->size ? lhs->size - 1 : rhs->size - 1;
	while (ii >= 0)
	{
		left = ii < lhs->size ? lhs->digits[ii] : 0;
		right = ii < rhs->size ? rhs->digits[ii] : 0;
		if (left == right)
		{
			ii--;
			continue ;
		}
		if (1 == lhs->sign && 1 == rhs->sign)
			return (left < right);
		if (-1 == lhs->sign && -1 == rhs->sign)
			return (left > right);
		ii--;
	}
	return (1);
}

int							countable_nbr_gte(t_countable_nbr *lhs, t_countable_nbr *rhs)
{
	return (0 == countable_nbr_lte(lhs, rhs));
}

t_countable_nbr				*countable_nbr_add
							(t_countable_nbr *lhs, t_countable_nbr *rhs)
{
	t_countable_nbr			*nbr;
	int						carry;
	int						rem;
	int						ii;

	if (lhs->size < rhs->size)
		ptr_swap((void **)&lhs, (void **)&rhs);
	nbr = new_countable_nbr(lhs->base, lhs->sign, lhs->size + 1);
	nbr->digits = ft_memcpy(nbr->digits, lhs->digits, lhs->size);
	ii = 0;
	while (ii < rhs->size)
	{
		if (lhs->sign == rhs->sign)
		{
			nbr->digits[ii] += rhs->digits[ii];
			carry = nbr->digits[ii] >= nbr->base;
			rem = nbr->digits[ii] - nbr->base;
			nbr->digits[ii] = rem;
			nbr->digits[ii + 1] += carry;
		}
		else
			nbr->digits[ii] -= rhs->digits[ii];
		ii++;
	}
	return (nbr);
}

t_countable_nbr				*countable_nbr_sub
							(t_countable_nbr *lhs, t_countable_nbr *rhs)
{
	rhs->sign = !rhs->sign;
	return (countable_nbr_add(lhs, rhs));
}

t_countable_nbr				*countable_nbr_mul
							(t_countable_nbr *lhs, t_countable_nbr *rhs)
{
	t_countable_nbr			*nbr;
	int						ii;
	int						jj;
	int						div;
	int						rem;

	if (lhs->size < rhs->size)
		ptr_swap((void **)&lhs, (void **)&rhs);
	nbr = new_countable_nbr(lhs->base, lhs->sign * rhs->sign, lhs->size + rhs->size);
	ii = 0;
	while (ii < lhs->size)
	{
		jj = 0;
		while (jj < rhs->size)
		{
			nbr->digits[ii + jj] += lhs->digits[ii] * rhs->digits[jj];
			div = nbr->digits[ii] / nbr->base;
			rem = nbr->digits[ii] - nbr->base * div;
			nbr->digits[ii] = rem;
			nbr->digits[ii + 1] += div;
			jj++;
		}
		ii++;
	}
	return (nbr);
}

t_countable_nbr				*countable_nbr_div
							(t_countable_nbr *lhs, t_countable_nbr *rhs)
{
	t_countable_nbr			*nbr;
	t_countable_nbr			*product;

	nbr = new_countable_nbr(lhs->base, 1, lhs->size);
	product = countable_nbr_mul(nbr, rhs);
	while (1 == countable_nbr_lte(product, lhs))
	{
		countable_nbr_inc(nbr);
		free_countable_nbr(&product);
		product = countable_nbr_mul(nbr, rhs);
	}
	free_countable_nbr(&product);
	return (countable_nbr_dec(nbr));
}

t_countable_nbr				*countable_nbr_mod
							(t_countable_nbr *lhs, t_countable_nbr *rhs)
{
	t_countable_nbr			*nbr;
	t_countable_nbr			*product;
	t_countable_nbr			*sub;

	nbr = new_countable_nbr(lhs->base, 1, lhs->size);
	product = countable_nbr_mul(nbr, rhs);
	while (1 == countable_nbr_lte(product, lhs))
	{
		countable_nbr_inc(nbr);
		free_countable_nbr(&product);
		product = countable_nbr_mul(nbr, rhs);
	}
	sub = countable_nbr_sub(lhs, product);
	free_countable_nbr(&nbr);
	free_countable_nbr(&product);
	return (sub);
}

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

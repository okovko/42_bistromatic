/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countable_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:44:38 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/13 00:44:38 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "ft_countable_nbr.h"

void						ptr_swap(void **aa, void **bb)
{
	void	*tmp;

	tmp = *aa;
	*aa = *bb;
	*bb = tmp;
}

t_node						new_node(void *data, int size)
{
	t_node					*node;

	node = malloc(sizeof(*node));
	node->data = data;
	node->next = NULL;
	node->size = size;
	return (node);
}

t_queue						new_queue_homog(int size, int data_size)
{
	t_queue					queue;
	t_node					*node;
	int						ii;

	queue.size = size >= 0 ? size : 0;
	queue.head = queue.size == 1 ? new_node(NULL, data_size) : NULL;
	queue.tail = queue.size == 2 ? new_node(NULL, data_size) : NULL;
	node = queue.head;
	ii = 2;
	while (ii < size)
	{
		node->next = new_node(NULL, data_size);
		node = node->next;
		ii++;
	}
	node->next = queue.tail;
	return (queue);
}

t_countable_nbr				*new_countable_nbr(int base, int sign, int size)
{
	t_countable_nbr			*new_nbr;
	t_node					*node;
	int						ii;

	new_nbr = malloc(sizeof(*new_nbr));
	new_nbr->base = base;
	new_nbr->size = size;
	new_nbr->queue = new_queue_homog(size, sizeof(int));
	return (new_nbr);
}

t_countable_nbr				*copy_countable_nbr(t_countable_nbr *dst, t_countable_nbr *src)
{
	t_node					*node;
	t_node					*copy;

	copy = src->digits->head;
	node = dst->digits->head;
	while (NULL != copy)
	{
		memcpy(node->data, copy->data, copy->size);
		copy = copy->next;
		node = node->next;
	}
	return (dst);
}

t_countable_nbr				*countable_nbr_distrib_carries(t_countable_nbr *nbr)
{
	t_node					*node;
	int						div;
	int						rem;

	node = nbr->digits->head;
	while (NULL != node->next)
	{
		div = *(int *)node->data >= nbr->base;
		rem = *(int *)node->data - nbr->base;
		*(int *)node->data = rem;
		*(int *)node->next->data += div;
		/*
		if (NULL == node->next)
			node->next = new_node(malloc(sizeof(node->size), node->size));
		*/
		node = node->next;
	}
	return (nbr);
}

t_countable_nbr				*countable_nbr_add
							(t_countable_nbr *lhs, t_countable_nbr *rhs)
{
	t_countable_nbr			*nbr;
	t_node					*lhs_node;
	t_node					*rhs_node;

	if (lhs->size < rhs->size)
		ptr_swap(&lhs, &rhs);
	nbr = new_countable_nbr(lhs->base, lhs->sign, lhs->size + 1);
	nbr = copy_countable_nbr(nbr, lhs);
	lhs_node = rhs->digits->head;
	rhs_node = nbr->digits->head;
	while (NULL != lhs_node)
	{
		if (lhs->sign == rhs->sign)
			*(int *)rhs_node->data += *(int *)lhs_node->data;
		else
			*(int *)rhs_node->data -= *(int *)lhs_node->data;
		lhs_node = lhs_node->next;
	}
	nbr->sign = lhs->sign;
	return (countable_nbr_distrib_carries(nbr));
}

t_countable_nbr				*countable_nbr_sub
							(t_countable_nbr *lhs, t_countable_nbr *rhs)
{
	t_countable_nbr			*nbr;
	t_node					*lhs_node;
	t_node					*rhs_node;

	if (lhs->size < rhs->size)
		ptr_swap(&lhs, &rhs);
	nbr = new_countable_nbr(lhs->base, lhs->sign, lhs->size + 1);
	nbr = copy_countable_nbr(nbr, lhs);
	lhs_node = rhs->digits->head;
	rhs_node = nbr->digits->head;
	while (NULL != lhs_node)
	{
		if (lhs->sign != rhs->sign)
			*(int *)rhs_node->data += *(int *)lhs_node->data;
		else
			*(int *)rhs_node->data -= *(int *)lhs_node->data;
		lhs_node = lhs_node->next;
	}
	nbr->sign = lhs->sign;
	return (countable_nbr_distrib_carries(nbr));
}

t_countable_nbr				*countable_nbr_mul
							(t_countable_nbr *lhs, t_countable_nbr *rhs)
{
	t_countable_nbr			*nbr;
	t_node					*lhs_node;
	t_node					*rhs_node;

	nbr = new_countable_nbr(lhs->base, lhs->sign, lhs->size + rhs->size);
	lhs_node = rhs->digits->head;
	while (NULL != lhs_node)
	{
		rhs_node = nbr->digits->head;
		while (NULL != rhs_node)
		{

			rhs_node = rhs_node->next;
		}
		lhs_node = lhs_node->next;
	}
	nbr->sign = lhs->sign;
	return (countable_nbr_distrib_carries(nbr));
}

t_countable_nbr				sub_countable_nbrs
							(t_countable_nbr *aa, t_countable_nbr *bb)
{

}

t_countable_nbr				mul_countable_nbrs
							(t_countable_nbr *aa, t_countable_nbr *bb)
{

}

t_countable_nbr				div_countable_nbrs
							(t_countable_nbr *aa, t_countable_nbr *bb)
{

}

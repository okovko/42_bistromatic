/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countable_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 09:34:23 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 09:34:23 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "ft_countable_nbr.h"
#include "bistromatic.h"

int							main(int ac, char **av)
{
	if (4 != ac)
		return (0);
	if (0 == grammar(av[1], av[2], atoi(av[3])))
		write(1, "syntax error\n", 5);
	// i ran out of time :P
	return (0);
}

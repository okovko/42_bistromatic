/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 12:06:06 by olkovale          #+#    #+#             */
/*   Updated: 2017/04/22 21:50:36 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"

int		ft_atoi(char *str)
{
	char	c;
	int		num;
	int		neg;

	if (str == 0)
		return (0);
	while ((c = *str) && ISSPACE(c))
		++str;
	neg = c == '-';
	str += c == '-' || c == '+';
	num = 0;
	while ((c = *str++) && ISDIGIT(c))
	{
		num *= 10;
		num += c - '0';
	}
	return (neg ? -num : num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 13:31:05 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/10 04:38:38 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MY_INT_MIN (~(~0u << 1))

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int is_int_min;

	is_int_min = 0;
	if (n < 0)
	{
		ft_putchar('-');
		if ((unsigned)n == MY_INT_MIN)
		{
			is_int_min = 1;
			n += 1;
		}
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0' + is_int_min);
	}
}

void	ft_putstr(char *str)
{
	while (str && *str)
		ft_putchar(*str++);
}

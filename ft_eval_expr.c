/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_expr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:56:11 by olkovale          #+#    #+#             */
/*   Updated: 2017/04/22 21:21:52 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "ft_eval_expr.h"
#include "ft_atoi.h"

int		eval_expr(char *str)
{
	char	*head;
	char	*stripped;
	int		eval;

	stripped = strip_non_symbols(str);
	head = stripped;
	eval = parse_sums(&stripped);
	free(head);
	return (eval);
}

int		parse_subexpr(char **expr)
{
	int		num;

	printf("parsing subexpr from %s\n", *expr);
	if ('(' == **expr)
		*expr += 1;
	num = parse_sums(expr);
	printf("parse_subexpr num = %d\n", num);
	return (num);
}

int		parse_num(char **expr)
{
	int		num;
	char	symbol;

	symbol = **expr;
	if (!ISDIGIT(symbol) && '-' != symbol && '+' != symbol)
		return (parse_subexpr(expr));
	printf("parsing num from %s\n", *expr);
	num = ft_atoi(*expr);
	printf("parse_num num = %d\n", num);
	*expr = next_symbol(*expr);
	return (num);
}

int		parse_factors(char **expr)
{
	int		num1;
	int		num2;
	char	symbol;

	num1 = parse_num(expr);
	while ((symbol = **expr))
	{
		if (!ISOP_FACTOR(symbol))
			return (num1);
		*expr += 1;
		num2 = parse_num(expr);
		printf("parse_factors num1 = %d\n", num1);
		printf("parse_factors symbol = %c\n", symbol);
		printf("parse_factors num2 = %d\n", num2);
		if (symbol == '/')
			num1 /= num2;
		else if (symbol == '*')
			num1 *= num2;
		else
			num1 %= num2;
		printf("parse_factors factor = %d\n", num1);
	}
	return (num1);
}

int		parse_sums(char **expr)
{
	int		num1;
	int		num2;
	char	symbol;

	num1 = parse_factors(expr);
	while ((symbol = **expr))
	{
		if (!ISOP_SUM(symbol))
		{
			if (')' == symbol)
				*expr += 1;
			return (num1);
		}
		*expr += 1;
		num2 = parse_factors(expr);
		printf("parse_sums num1 = %d\n", num1);
		printf("parse_sums symbol = %c\n", symbol);
		printf("parse_sums num2 = %d\n", num2);
		if (symbol == '-')
			num1 -= num2;
		else
			num1 += num2;
		printf("parse_sums sum = %d\n", num1);
	}
	return (num1);
}

char	*next_symbol(char *str)
{
	char	cc;

	if (str == NULL)
		return (NULL);
	str += *str != '\0';
	while ((cc = *str) && ISDIGIT(cc))
		str++;
	return (str);
}

char	*strip_non_symbols(char *str)
{
	int		symbol_count;
	char	*stripped;

	if (str == NULL)
		return (NULL);
	symbol_count = str_count_if(str, is_symbol);
	stripped = malloc(symbol_count + 1);
	return (str_cpy_if(stripped, str, is_symbol));
}

char	*str_cpy_if(char *dst, char *src, int (*ff)(char))
{
	char	cc;
	char	*head;

	if (dst == NULL || src == NULL || ff == NULL)
		return (NULL);
	head = dst;
	while ((cc = *src++))
		if (ff(cc))
			*dst++ = cc;
	*dst = '\0';
	return (head);
}

int		str_count_if(char *str, int (*ff)(char))
{
	char	cc;
	int		count;

	if (str == NULL)
		return (0);
	count = 0;
	while ((cc = *str++))
		count += ff(cc);
	return (count);
}

int		is_symbol(char cc)
{
	return (ISSYMBOL(cc));
}

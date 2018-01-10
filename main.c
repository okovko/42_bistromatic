/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 18:11:49 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/10 04:47:54 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "ft_eval_expr.h"
#include "ft_print.h"

void	run_case(char *input, int expected)
{
	int		eval;

	printf("Input: %s\n", input);
	eval = eval_expr(input);
	if (eval == expected)
		printf("%c[%d;%dmOK.%c[%dm\n", 27, 1, 32, 27, 0);
	else
		printf("%c[%d;%dmFAIL.%c[%dm Expected %d, but got %d\n", 27, 1, 31, 27, 0, expected, eval);
}

void	run_tests()
{
	printf("Tests...\n");
	run_case("2 + 3", 5);
	printf("\n");
	run_case("2 - 3", -1);
	printf("\n");
	run_case("2 * 3", 6);
	printf("\n");
	run_case("2 / 3", 0);
	printf("\n");
	run_case("2 % 3", 2);
	printf("\n");
	run_case("10 + 2 * 6", 22);
	printf("\n");
	run_case("100 * 2 + 12", 212);
	printf("\n");
	run_case("100 * ( 2 + 12 )", 1400);
	printf("\n");
	run_case("100 * ( 2 + 12 ) / 14", 100);
	printf("\n");
	run_case("3 + 42 * (1 - 2 / (3 + 4) - 1 % 21) + 1", 4);
	printf("\n");
	printf("Going crazy...\n");
	printf("\n");
	run_case("3 * -1", -3);
	printf("\n");
	run_case("-1 + -1", -2);
	printf("\n");
	run_case("-1 - -1", 0);
	printf("\n");
	run_case("(3) + (3) * (-3)", -6);
	printf("\n");
	run_case("(3) + ((42) * ((1) - ((2) / ((3) + (4))) - (1)) % (21)) + (1)", 4);
	printf("\n");
	run_case("3 + (42 * (1 - (2 / (3 + 4)) - 1) % 21) + 1", 4);
	printf("\n");
	run_case("(1 + ((2 * (3 - (4 / (5 + 6)))) - 1 % 21)) + 1", 7);
	printf("\n");
	run_case("(2147483647 * 1 - 10) * -1", -2147483637);
	printf("\n");
	run_case("(-2147483648 + 1) * -1", 2147483647);
	printf("\n");
	run_case("-2147483648 / -2", 1073741824);
	printf("\n");
	run_case("(-2147483646 + -2 + 1) * -1", 2147483647);
	printf("\n");
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_putnbr(eval_expr(argv[1]));
		ft_putchar('\n');
	}
	run_tests();
	return (0);
}

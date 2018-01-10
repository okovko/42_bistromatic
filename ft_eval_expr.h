/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_expr.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:56:18 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/10 04:47:56 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

#define ISPAREN(c) (c == '(' || c == ')')
#define ISOP_SUM(c) (c == '+' || c == '-')
#define ISOP_FACTOR(c) (c == '*' || c == '/' || c == '%')
#define ISOP(c) (ISOP_SUM(c) || ISOP_FACTOR(c))
#define ISSYMBOL(c) (ISDIGIT(c) || ISOP(c) || ISPAREN(c))

int		eval_expr(char *str);
int		parse_subexpr(char **expr);
int		parse_num(char **expr);
int		parse_factors(char **expr);
int		parse_sums(char **expr);
char	*next_symbol(char *str);
char	*strip_non_symbols(char *str);
char	*str_cpy_if(char *dst, char *src, int (*ff)(char));
int		str_count_if(char *str, int (*ff)(char));
int		is_symbol(char cc);

#endif

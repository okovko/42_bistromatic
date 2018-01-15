/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_expr.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 16:56:18 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 07:59:05 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTROMATIC_H
# define BISTROMATIC_H

#include "ft_countable_nbr.h"

#define ISSPACE(c) (c == ' ')
#define ISDIGIT(c) (c >= '0' && c <= '9')
#define ISPAREN(c) (c == '(' || c == ')')
#define ISOP_SUM(c) (c == '+' || c == '-')
#define ISOP_FACTOR(c) (c == '*' || c == '/' || c == '%')
#define ISOP(c) (ISOP_SUM(c) || ISOP_FACTOR(c))
#define ISSYMBOL(c) (ISDIGIT(c) || ISOP(c) || ISPAREN(c))

#define ABS(x) ((x) < 0 ? -(x) : (x))

void						*ft_memcpy(void *dst, const void *src, int size);
void						*ft_memset(void *mem, int set, int size);
int							ft_nbrlen(int value);
int							eval_expr(char *str);
void						ft_ptrswap(void **aa, void **bb);
int							ft_atoi(char *str);

t_countable_nbr				*new_countable_nbr(int base, int sign, int size);
void						free_countable_nbr(t_countable_nbr **nbr);
t_countable_nbr				*countable_nbr_distrib_inc_or_dec(t_countable_nbr *nbr);
t_countable_nbr				*countable_nbr_inc(t_countable_nbr *nbr);
t_countable_nbr				*countable_nbr_dec(t_countable_nbr *nbr);
int							countable_nbr_lte(t_countable_nbr *lhs, t_countable_nbr *rhs);
int							countable_nbr_gte(t_countable_nbr *lhs, t_countable_nbr *rhs);
t_countable_nbr				*countable_nbr_add
							(t_countable_nbr *lhs, t_countable_nbr *rhs);
t_countable_nbr				*countable_nbr_sub
							(t_countable_nbr *lhs, t_countable_nbr *rhs);
t_countable_nbr				*countable_nbr_mul
							(t_countable_nbr *lhs, t_countable_nbr *rhs);
t_countable_nbr				*countable_nbr_div
							(t_countable_nbr *lhs, t_countable_nbr *rhs);
t_countable_nbr				*countable_nbr_mod
							(t_countable_nbr *lhs, t_countable_nbr *rhs);

int							check_parens_matching(char *input, int size);
int							check_end(char *digits, char *input, int pos, int size);
int							check_close(char *digits, char *input, int pos, int size);
int							check_open(char *digits, char *input, int pos, int size);
int							check_num(char *digits, char *input, int pos, int size);
int							check_binary(char *digits, char *input, int pos, int size);
int							check_unary(char *digits, char *input, int pos, int size);
int							grammar(char *digits, char *input, int size);

int							parse_subexpr(char **expr);
int							parse_num(char **expr);
int							parse_factors(char **expr);
int							parse_sums(char **expr);
char						*next_symbol(char *str);
char						*strip_non_symbols(char *str);
char						*str_cpy_if(char *dst, char *src, int (*ff)(char));
int							str_count_if(char *str, int (*ff)(char));
int							is_symbol(char cc);

#endif

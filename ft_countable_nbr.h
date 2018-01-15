/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countable_nbr.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 00:45:01 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/15 04:33:49 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COUNTABLE_NBR_H
# define FT_COUNTABLE_NBR_H

#include <stdlib.h>

typedef struct				s_countable_nbr
{
	int						base;
	int						sign;
	int						size;
	char					*digits;
}							t_countable_nbr;

#endif

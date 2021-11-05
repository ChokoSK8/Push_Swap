/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:11:59 by abrun             #+#    #+#             */
/*   Updated: 2021/11/02 15:02:18 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	is_rot_or_rev_align(t_stack *stk)
{
	double		n_rev;
	double		half;

	half = ft_stksize(stk) / 2.000;
	n_rev = get_n_rev(stk);
	if (n_rev < half)
		return (0);
	return (1);
}

int	is_more_staying(t_stack *stk)
{
	t_meth		method;
	int			n_stk;
	int			n_tmp;

	n_stk = count_keep(stk);
	method = get_method(stk);
	clear_keep(stk);
	put_keep(stk, method);
	n_tmp = count_keep(stk);
	if (n_stk >= n_tmp)
		return (0);
	return (1);
}

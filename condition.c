/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:26:20 by abrun             #+#    #+#             */
/*   Updated: 2021/04/20 15:49:29 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int			get_n_rev_sp(t_stack *stk)
{
	int		n_rev;

	n_rev = 1;
	while (stk && stk->keep == 1)
	{
		stk = stk->next;
		n_rev++;
	}
	return (n_rev);
}

int			is_rot_or_rev(t_stack *stk)
{
	int		n_rev;
	int		n_rot;

	n_rev = get_n_rev_sp(stk);
	n_rot = 0;
	while (stk)
	{
		while (stk && stk->keep == 1)
		{
			stk = stk->next;
			n_rot ++;
		}
		if (stk)
		{
			n_rot = 0;
			stk = stk->next;
		}
	}
	if (n_rev < n_rot)
		return (0);
	return (1);
}

int			is_swap_needed(t_stack *stk, t_meth *method)
{
	t_stack		*tmp;
	t_meth		toad;

	tmp = duplicate_stk(stk);
	if (ft_stksize(stk) > 2)
	{
		clear_keep(tmp);
		ft_swap(&tmp);
		toad = get_method(tmp);
		if (toad.nbr > method->nbr)
		{
			method->nbr = toad.nbr;
			method->name = toad.name;
			method->from = toad.from;
			free_tmp(&tmp);
			return (1);
		}
	}
	free_tmp(&tmp);
	return (0);
}

int			is_top_disp(t_stack *stk)
{
	while (stk->next)
		stk = stk->next;
	if (stk->keep == 0)
		return (1);
	return (0);
}

int			is_threw_away(t_stack *stk)
{
	while (stk)
	{
		if (stk->keep == 0)
			return (1);
		stk = stk->next;
	}
	return (0);
}

int				is_rot_or_rev_align(t_stack *stk)
{
	int		n_rev;
	int		half;

	half = ft_stksize(stk) / 2;
	n_rev = get_n_rev(stk);
	printf("n_rev : %d\n", n_rev);
	printf("half : %d\n", half);
	if (n_rev < half)
		return (0);
	return (1);
}

int				is_more_staying(t_stack *stk)
{
	t_stack		*tmp;
	t_meth		method;
	int			n_stk;
	int			n_tmp;

	tmp = duplicate_stk(stk);
	method = get_method(stk);
	clear_keep(tmp);
	put_keep(tmp, method);
	n_stk = count_keep(stk);
	n_tmp = count_keep(tmp);
	if (n_stk >= n_tmp)
		return (0);
	return (1);
}

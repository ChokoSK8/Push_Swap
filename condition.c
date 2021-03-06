/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:26:20 by abrun             #+#    #+#             */
/*   Updated: 2021/11/02 15:08:13 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	get_n_rot_sp(t_stack *stk)
{
	int		n_rot;

	n_rot = 1;
	while (stk && stk->keep == 1)
	{
		stk = stk->next;
		n_rot++;
	}
	return (n_rot);
}

int	is_rot_or_rev(t_stack *stk)
{
	int		n_rev;
	int		n_rot;

	n_rot = get_n_rot_sp(stk);
	n_rev = 0;
	while (stk)
	{
		while (stk && stk->keep == 1)
		{
			stk = stk->next;
			n_rev++;
		}
		if (stk)
		{
			n_rev = 0;
			stk = stk->next;
		}
	}
	if (n_rev < n_rot)
		return (0);
	return (1);
}

int	is_swap_needed(t_stack *stk, t_meth *method)
{
	t_meth		toad;

	if (ft_stksize(stk) > 2)
	{
		clear_keep(stk);
		ft_swap(&stk);
		toad = get_method(stk);
		ft_swap(&stk);
		clear_keep(stk);
		put_keep(stk, *method);
		if (toad.nbr > method->nbr)
		{
			method->nbr = toad.nbr;
			method->name = toad.name;
			method->from = toad.from;
			return (1);
		}
	}
	return (0);
}

int	is_top_disp(t_stack *stk)
{
	if (stk->keep == 0)
		return (1);
	return (0);
}

int	is_threw_away(t_stack *stk)
{
	while (stk)
	{
		if (stk->keep == 0)
			return (1);
		stk = stk->next;
	}
	return (0);
}

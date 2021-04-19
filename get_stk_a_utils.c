/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stk_a_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:10:12 by abrun             #+#    #+#             */
/*   Updated: 2021/04/19 12:28:59 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int			get_min(t_stack *stk, int min)
{
	int		max;

	max = 2147483647;
	while (stk)
	{
		if (stk->content <= max && stk->content > min)
			max = stk->content;
		stk = stk->next;
	}
	return (max);
}

t_stack		*put_keep_great(t_stack *stk)
{
	int		ret;

	ret = stk->content;
	while (stk->next)
	{
		stk = stk->next;
		if (stk->content > ret)
		{
			stk->keep = 1;
			ret = stk->content;
		}
	}
	return (stk);
}

t_stack		*put_keep_index(t_stack *stk)
{
	int		ret;

	ret = stk->index;
	while (stk->next)
	{
		stk = stk->next;
		if (stk->index == ret + 1)
		{
			stk->keep = 1;
			ret = stk->index;
		}
	}
	return (stk);
}

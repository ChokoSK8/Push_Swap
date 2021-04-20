/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:37:31 by abrun             #+#    #+#             */
/*   Updated: 2021/04/20 13:48:56 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int			count_keep(t_stack *stk)
{
	int		n;

	n = 0;
	while (stk)
	{
		if (stk->keep == 1)
			n++;
		stk = stk->next;
	}
	return (n);
}

int		get_n_rev(t_stack *stk)
{
	int		n_rev;

	n_rev = 0;
	while (stk && stk->index != 0)
	{
		stk = stk->next;
		n_rev += 1;
	}
	return (n_rev);
}

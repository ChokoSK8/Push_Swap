/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:37:31 by abrun             #+#    #+#             */
/*   Updated: 2021/04/19 11:45:47 by abrun            ###   ########.fr       */
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

t_stack		*get_n_rev(t_stack *stk, int *n_rev)
{
	while (stk && stk->keep == 1)
	{
		stk = stk->next;
		*n_rev += 1;
	}
	return (stk);
}

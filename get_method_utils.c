/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_method_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:50:30 by abrun             #+#    #+#             */
/*   Updated: 2021/04/19 12:03:39 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		get_n_greater(t_stack *stk, int ret)
{
	int		n;

	n = 1;
	while (stk)
	{
		if (ret < stk->content)
		{
			ret = stk->content;
			n++;
		}
		stk = stk->next;
	}
	return (n);
}

int		get_n_index(t_stack *stk, int ret)
{
	int		n;

	n = 1;
	while (stk)
	{
		if (stk->index == ret - 1)
		{
			ret = stk->index;
			n++;
		}
		stk = stk->next;
	}
	return (n);
}

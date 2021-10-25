/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_stk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:35:29 by abrun             #+#    #+#             */
/*   Updated: 2021/10/25 17:50:11 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stack	*align_stack_a(t_stack *stk)
{
	t_meth		method;
	int			rot;

	rot = is_rot_or_rev_align(stk);
	while (!is_align(stk))
	{
		method = get_method(stk);
		clear_keep(stk);
		put_keep(stk, method);
		if (!rot)
		{
			printf("ra\n");
			stk = ft_rotate(&stk);
		}
		else
		{
			printf("rra\n");
			stk = ft_rev_rot(&stk);
		}
	}
	return (stk);
}

int	is_align(t_stack *stk)
{
	t_stack		*next;
	int			cur;

	next = stk;
	while (next->next)
	{
		cur = next->content;
		next = next->next;
		if (cur > next->content)
			return (0);
	}
	return (1);
}

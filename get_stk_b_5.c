/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stk_b_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:02:07 by abrun             #+#    #+#             */
/*   Updated: 2021/10/26 16:27:10 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stacks	get_stack_b_5(t_stack *stk_a)
{
	int			len_a;
	t_stack		*stk_b;
	t_stacks	s;
	t_meth		meth;

	stk_b = NULL;
	meth = get_method(stk_a);
	put_keep(stk_a, meth);
	s.a = stk_a;
	s.b = stk_b;
	len_a = ft_stksize(stk_a);
	if (len_a < 3)
		return (s);
	while (is_threw_away(stk_a) && len_a-- > 3)
	{
		ft_putstr_fd(1, "pb\n");
		stk_b = ft_push(&stk_a, &stk_b);
	}
	stk_a = sort_stk_a_3(stk_a);
	s.a = stk_a;
	s.b = stk_b;
	return (s);
}

t_stack	*sort_stk_a_3(t_stack *stk)
{
	if (is_sorted_3(stk))
		return (stk);
	if (stk->index > stk->next->index)
	{
		ft_putstr_fd(1, "sa\n");
		ft_swap(&stk);
	}
	else
	{
		ft_putstr_fd(1, "ra\n");
		stk = ft_rotate(&stk);
		ft_putstr_fd(1, "sa\n");
		ft_swap(&stk);
	}
	return (stk);
}

int	is_sorted_3(t_stack *stk)
{
	if (stk->next->next->index > stk->next->index
		&& stk->index > stk->next->next->index)
		return (1);
	else if (stk->index < stk->next->index
		&& stk->next->index < stk->next->next->index)
		return (1);
	else if (stk->index < stk->next->index
		&& stk->index > stk->next->next->index)
		return (1);
	return (0);
}

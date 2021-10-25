/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stk_b_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:20:04 by abrun             #+#    #+#             */
/*   Updated: 2021/10/25 18:01:30 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	get_n_rev_index(t_stack *stk, int index)
{
	int		res;

	res = 0;
	while (stk && stk->index != index)
	{
		stk = stk->next;
		res += 1;
	}
	return (res);
}

t_stack	*make_rot_or_rev_index(t_stack *stk, int index)
{
	int		n_rev;
	int		len;

	n_rev = get_n_rev_index(stk, index) + 1;
	len = ft_stksize(stk);
	if (len > 1 && n_rev > 0)
	{
		if (n_rev < len / 2)
		{
			while (n_rev--)
			{
				printf("rrb\n");
				stk = ft_rev_rot(&stk);
			}
		}
		else
		{
			while (n_rev++ < len)
			{
				printf("rb\n");
				stk = ft_rotate(&stk);
			}
		}
	}
	return (stk);
}

t_stack	*move_stk_b(t_stack *stk_b, t_stack *stk)
{
	int			index;
	int			target;
	t_stack		*next;
	int			n;
	int			min;

	while (stk->next)
		stk = stk->next;
	index = stk->index;
	target = 0;
	next = stk_b;
	min = index - stk_b->index;
	while (next)
	{
		n = index - next->index;
		if (abs(min) >= abs(n) && n > 0)
		{
			target = next->index;
			min = n;
		}
		next = next->next;
	}
	stk_b = make_rot_or_rev_index(stk_b, target);
	return (stk_b);
}

t_stack	*make_push(t_stack **stk, t_stack *stk_b)
{
	printf("pb\n");
	stk_b = ft_push(stk, &stk_b);
	return (stk_b);
}

t_stack	*make_rot_or_rev(t_stack *stk, t_meth *method)
{
	if (is_rot_or_rev(stk))
	{
		printf("ra\n");
		stk = ft_rotate(&stk);
	}
	else
	{
		printf("rra\n");
		stk = ft_rev_rot(&stk);
	}
	if (is_more_staying(stk))
	{
		*method = get_method(stk);
		clear_keep(stk);
		put_keep(stk, *method);
	}
	return (stk);
}

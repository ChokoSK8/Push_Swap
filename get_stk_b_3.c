/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stk_b_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:21:19 by abrun             #+#    #+#             */
/*   Updated: 2021/10/26 15:48:32 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	make_rrotate_2(t_stack **stack_a, t_stack **stack_b, t_meth *method)
{
	ft_putstr_fd(1, "rr\n");
	ft_rotate_r(stack_a, stack_b);
	if (is_more_staying(*stack_a))
	{
		*method = get_method(*stack_a);
		clear_keep(*stack_a);
		put_keep(*stack_a, *method);
	}
	return (1);
}

int	make_rrev_rot_2(t_stack **stack_a, t_stack **stack_b,
		t_meth *method)
{
	if (is_rot_or_rev(*stack_a))
	{
		ft_putstr_fd(1, "rr\n");
		ft_rotate_r(stack_a, stack_b);
	}
	else
	{
		ft_putstr_fd(1, "rrr\n");
		ft_rev_rot_r(stack_a, stack_b);
	}
	if (is_more_staying(*stack_a))
	{
		*method = get_method(*stack_a);
		clear_keep(*stack_a);
		put_keep(*stack_a, *method);
	}
	return (1);
}

t_stack	*make_rot(t_stack *stk, t_meth *method)
{
	ft_putstr_fd(1, "ra\n");
	stk = ft_rotate(&stk);
	if (is_more_staying(stk))
	{
		*method = get_method(stk);
		clear_keep(stk);
		put_keep(stk, *method);
	}
	return (stk);
}

int	make_swap_2(t_stack **stk, t_meth method, t_stack **stk_b)
{
	(void)stk_b;
	ft_putstr_fd(1, "sa\n");
	ft_swap(stk);
	clear_keep(*stk);
	put_keep(*stk, method);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stk_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:06:28 by abrun             #+#    #+#             */
/*   Updated: 2021/11/02 15:02:28 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stacks	get_stack_b(t_stack *stk)
{
	t_stack		*stack_b;
	t_stacks	s;
	t_meth		method;

	stack_b = NULL;
	method = get_method(stk);
	put_keep(stk, method);
	while (is_threw_away(stk))
	{
		if (is_swap_needed(stk, &method))
			make_swap_2(&stk, method, &stack_b);
		else if (is_top_disp(stk))
			stack_b = make_push(&stk, stack_b);
		else
			make_rrev_rot_2(&stk, &stack_b, &method);
		if (is_push_needed(stk, stack_b, &method))
			stk = make_push_needed(stk, &stack_b, method);
	}
	s.a = stk;
	s.b = stack_b;
	return (s);
}

int	is_push_needed(t_stack *stk_a, t_stack *stk_b, t_meth *method)
{
	t_meth		toad;

	if (stk_b)
	{
		clear_keep(stk_a);
		stk_a = ft_push(&stk_b, &stk_a);
		toad = get_method(stk_a);
		stk_b = ft_push(&stk_a, &stk_b);
		clear_keep(stk_a);
		put_keep(stk_a, *method);
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

t_stack	*make_push_needed(t_stack *stk, t_stack **stk_b, t_meth method)
{
	ft_putstr_fd(1, "pa\n");
	stk = ft_push(stk_b, &stk);
	clear_keep(stk);
	put_keep(stk, method);
	return (stk);
}

int	make_swap(t_stack **stk, t_meth method)
{
	ft_putstr_fd(1, "sa\n");
	ft_swap(stk);
	clear_keep(*stk);
	put_keep(*stk, method);
	return (1);
}

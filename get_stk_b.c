/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stk_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:06:28 by abrun             #+#    #+#             */
/*   Updated: 2021/10/23 16:08:50 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stacks		get_stack_b(t_stack *stk)
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

int				is_push_needed(t_stack *stk_a, t_stack *stk_b, t_meth *method)
{
	t_stack		*tmp_b;
	t_stack		*tmp_a;
	t_meth		toad;

	if (stk_b)
	{
		tmp_b = duplicate_stk(stk_b);
		tmp_a = duplicate_stk(stk_a);
		clear_keep(tmp_a);
		clear_keep(tmp_b);
		tmp_a = ft_push(&tmp_b, &tmp_a);
		toad = get_method(tmp_a);
		if (toad.nbr > method->nbr)
		{
			method->nbr = toad.nbr;
			method->name = toad.name;
			method->from = toad.from;
			free_tmp(&tmp_a);
			free_tmp(&tmp_b);
			return (1);
		}
		free_tmp(&tmp_a);
		free_tmp(&tmp_b);
	}
	return (0);
}

t_stack			*make_push_needed(t_stack *stk, t_stack **stk_b, t_meth method)
{
	printf("pb\n");
	stk = ft_push(stk_b, &stk);
	clear_keep(stk);
	put_keep(stk, method);
	return (stk);
}

int				make_swap(t_stack **stk, t_meth method)
{
	printf("sa\n");
	ft_swap(stk);
	clear_keep(*stk);
	put_keep(*stk, method);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stk_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:06:28 by abrun             #+#    #+#             */
/*   Updated: 2021/04/19 14:12:31 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stacks		get_stack_b(t_stack *stk, int *counter)
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
			*counter += make_swap(&stk, method);
		else if (is_top_disp(stk))
			stack_b = make_push(&stk, stack_b, counter);
		else
			stk = make_rot_or_rev(stk, &method, counter);
	}
	s.a = stk;
	s.b = stack_b;
	return (s);
}

int			make_swap(t_stack **stk, t_meth method)
{
	printf("SWAP\n");
	ft_sab(*stk);
	clear_keep(*stk);
	put_keep(*stk, method);
	return (1);
}

t_stack		*make_push(t_stack **stk, t_stack *stk_b, int *counter)
{
	printf("PUSH\n");
	*counter += 1;
	stk_b = (ft_push(stk, &stk_b));
	return (stk_b);
}

t_stack		*make_rot_or_rev(t_stack *stk, t_meth *method, int *counter)
{
	if (is_rot_or_rev(stk))
	{
		printf("ROTATE\n");
		*counter += 1;
		stk = ft_rotate(&stk);
	}
	else
	{
		printf("REV-ROTATE\n");
		*counter += 1;
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

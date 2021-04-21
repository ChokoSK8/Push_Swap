/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:15:42 by abrun             #+#    #+#             */
/*   Updated: 2021/04/21 11:15:51 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void		ft_swap(t_stack **stk)
{
	t_stack		*a;
	int			n;
	t_stack		*last;
	t_stack		*tmp;

	n = ft_stksize(*stk);
	a = *stk;
	if (n == 2)
	{
		last = (*stk)->next;
		last->next = *stk;
		(*stk)->next = NULL;
		*stk = last;
	}
	else
	{
		while (--n > 2)
			a = a->next;
		last = ft_stklast(*stk);
		tmp = a->next;
		a->next = last;
		last->next = tmp;
		tmp->next = NULL;
	}
}

int			ft_sab(t_stack **stack)
{
	int		n;

	n = ft_stksize(*stack);
	if (n > 1)
		ft_swap(stack);
	return (1);
}

int			ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sab(&stack_a);
	ft_sab(&stack_b);
	return (1);
}

int			ft_rev_rot_r(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = ft_rev_rot(stack_a);
	*stack_b = ft_rev_rot(stack_b);
	return (1);
}

int			ft_rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = ft_rotate(stack_a);
	*stack_b = ft_rotate(stack_b);
	return (1);
}

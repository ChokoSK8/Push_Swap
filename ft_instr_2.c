/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:15:42 by abrun             #+#    #+#             */
/*   Updated: 2021/10/26 12:05:50 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_swap(t_stack **stk)
{
	t_stack	*tmp;
	int		n;

	n = ft_stksize(*stk);
	if (n > 1)
	{
		tmp = (*stk)->next;
		(*stk)->next = tmp->next;
		tmp->next = *stk;
		*stk = tmp;
	}
}

int	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(&stack_a);
	ft_swap(&stack_b);
	return (1);
}

int	ft_rev_rot_r(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = ft_rev_rot(stack_a);
	*stack_b = ft_rev_rot(stack_b);
	return (1);
}

int	ft_rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = ft_rotate(stack_a);
	*stack_b = ft_rotate(stack_b);
	return (1);
}

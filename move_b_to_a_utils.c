/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:54:40 by abrun             #+#    #+#             */
/*   Updated: 2021/10/26 15:50:58 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	make_rrotate(t_stack **stack_a, t_stack **stack_b, int *count)
{
	int		counter;

	counter = 0;
	while (count[0] > 0 && count[1] > 0)
	{
		ft_putstr_fd(1, "rr\n");
		counter++;
		ft_rotate_r(stack_a, stack_b);
		count[0] -= 1;
		count[1] -= 1;
	}
	return (counter);
}

int	make_rrev_rot(t_stack **stack_a, t_stack **stack_b, int *count)
{
	int		counter;

	counter = 0;
	while (count[0] > 0 && count[1] > 0)
	{
		ft_putstr_fd(1, "rrr\n");
		counter++;
		ft_rev_rot_r(stack_a, stack_b);
		count[0] -= 1;
		count[1] -= 1;
	}
	return (counter);
}

t_stack	*make_rev_or_rot_a(t_stack *stk, int *ret, t_param *param)
{
	if (!((int)param->len[0] % 2))
	{
		stk = make_ra_rra_pair(stk, ret, param);
	}
	else
	{
		stk = make_ra_rra_odd(stk, ret, param);
	}
	return (stk);
}

t_stack	*make_rev_or_rot_b(t_stack *stk, int *ret, t_param *param)
{
	if (!((int)param->len[1] % 2))
	{
		stk = make_rb_rrb_pair(stk, ret, param);
	}
	else
	{
		stk = make_rb_rrb_odd(stk, ret, param);
	}
	return (stk);
}

t_stack	*make_last_step(t_stack *stk_a, t_stack **stk_b)
{
	ft_putstr_fd(1, "pa\n");
	stk_a = ft_push(stk_b, &stk_a);
	if (is_swap_needed_align(stk_a))
	{
		ft_putstr_fd(1, "sa\n");
		ft_swap(&stk_a);
	}
	return (stk_a);
}

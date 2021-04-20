/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:54:40 by abrun             #+#    #+#             */
/*   Updated: 2021/04/20 16:59:46 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int			make_rrotate(t_stack **stack_a, t_stack **stack_b, int *count)
{
	int		counter;

	counter = 0;
	while (count[0] > 0 && count[1] > 0)
	{
		printf("R_ROTATE\n");
		counter++;
		ft_rotate_r(stack_a, stack_b);
		count[0] -= 1;
		count[1] -= 1;
	}
	return (counter);
}

int			make_rrev_rot(t_stack **stack_a, t_stack **stack_b, int *count)
{
	int		counter;

	counter = 0;
	while (count[0] > 0 && count[1] > 0)
	{
		printf("R_ROTATE\n");
		counter++;
		ft_rev_rot_r(stack_a, stack_b);
		count[0] -= 1;
		count[1] -= 1;
	}
	return (counter);
}

t_stack			*make_rev_or_rot_a(t_stack *stk, int *ret, int *counter, t_param *param)
{
	(void)ret;
	if ((double)(ret[2] + 1) >= param->len[0] / 2.0000)
	{
		while (param->count[0]--)
		{
			printf("ROTATE_a\n");
			*counter += 1;
			stk = ft_rotate(&stk);
		}
	}
	else
	{
		while (param->count[0]--)
		{
			printf("REV-ROTATE_a\n");
			*counter += 1;
			stk = ft_rev_rot(&stk);
		}
	}
	return (stk);
}

t_stack			*make_rev_or_rot_b(t_stack *stk, int *ret, int *counter, t_param *param)
{
	(void)ret;
	if ((double)(ret[1] + 1) >= param->len[1] / 2.0000)
	{
		while (param->count[1]--)
		{
			printf("ROTATE_b\n");
			*counter += 1;
			stk = ft_rotate(&stk);
		}
	}
	else
	{
		while (param->count[1]--)
		{
			printf("REV-ROTATE_b\n");
			*counter += 1;
			stk = ft_rev_rot(&stk);
		}
	}
	return (stk);
}

t_stack			*make_last_step(t_stack *stk_a, int *counter, t_stack **stk_b)
{
	printf("PUSH_A\n");
	*counter += 1;
	stk_a = ft_push(stk_b, &stk_a);
	if (is_swap_needed_align(stk_a))
	{
		if (is_swap_needed_b(*stk_b))
		{
			printf("S-SWAP\n");
			*counter += 1;
			ft_sab(&stk_a);
			ft_sab(stk_b);
		}
		else
		{
			printf("SWAP\n");
			*counter += 1;
			ft_sab(&stk_a);
		}
	}
	return (stk_a);
}
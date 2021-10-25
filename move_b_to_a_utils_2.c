/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:40:17 by abrun             #+#    #+#             */
/*   Updated: 2021/10/25 18:24:16 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stack	*make_ra_rra_pair(t_stack *stk, int *ret, t_param *param)
{
	if ((double)(ret[2] + 1) <= param->len[0] / 2.0000)
	{
		while (param->count[0]--)
		{
			printf("ra\n");
			stk = ft_rotate(&stk);
		}
	}
	else
	{
		while (param->count[0]--)
		{
			printf("rra\n");
			stk = ft_rev_rot(&stk);
		}
	}
	return (stk);
}

t_stack	*make_ra_rra_odd(t_stack *stk, int *ret, t_param *param)
{
	if ((double)(ret[2] + 1) <= (param->len[0] / 2.0000) + 1)
	{
		while (param->count[0]--)
		{
			printf("ra\n");
			stk = ft_rotate(&stk);
		}
	}
	else
	{
		while (param->count[0]--)
		{
			printf("rra\n");
			stk = ft_rev_rot(&stk);
		}
	}
	return (stk);
}

t_stack	*make_rb_rrb_odd(t_stack *stk, int *ret, t_param *param)
{
	if ((double)(ret[1] + 1) <= (param->len[1] / 2.0000) + 1)
	{
		while (param->count[1]--)
		{
			printf("rb\n");
			stk = ft_rotate(&stk);
		}
	}
	else
	{
		while (param->count[1]--)
		{
			printf("rrb\n");
			stk = ft_rev_rot(&stk);
		}
	}
	return (stk);
}

t_stack	*make_rb_rrb_pair(t_stack *stk, int *ret, t_param *param)
{
	if ((double)(ret[1] + 1) <= param->len[1] / 2.0000)
	{
		while (param->count[1]--)
		{
			printf("rb\n");
			stk = ft_rotate(&stk);
		}
	}
	else
	{
		while (param->count[1]--)
		{
			printf("rrb\n");
			stk = ft_rev_rot(&stk);
		}
	}
	return (stk);
}

int	is_same_command(t_stack *stk_a, t_stack *stk_b,
		int pos_b, int pos_a)
{
	int		len_a;
	int		len_b;
	int		rot_a;
	int		rot_b;

	len_a = ft_stksize(stk_a);
	len_b = ft_stksize(stk_b);
	rot_a = get_rot(pos_a, len_a);
	rot_b = get_rot(pos_b, len_b);
	if (rot_a == rot_b)
		return (1);
	return (0);
}

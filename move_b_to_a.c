/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:51:32 by abrun             #+#    #+#             */
/*   Updated: 2021/04/19 16:29:49 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stack		*move_b_to_a(t_stack *stack_a, t_stack *stack_b, int *counter)
{
	int			size_b;
	int			*ret;
	t_param		param;

	if (!(ret = malloc(sizeof(int) * 3)))
		return (0);
	size_b = ft_stksize(stack_b);
	while (size_b--)
	{
		get_choosen(stack_a, stack_b, ret);
	//	printf("On fait %d opérations\n", ret[0]);
		param.len[0] = ft_stksize(stack_a);
		param.len[1] = ft_stksize(stack_b);
		param.count[0] = get_moves_b(stack_a, ret[2]);
		param.count[1] = get_moves_b(stack_b, ret[1]);
		if ((double)(ret[2] + 1) >= param.len[0] / 2.0000
			&& (double)(ret[1] + 1) >= param.len[1] / 2.0000)
			*counter += make_rrotate(&stack_a, &stack_b, param.count);
		else if ((double)(ret[2] + 1) < param.len[0] / 2.0000
			&& (double)(ret[1] + 1) < param.len[1] / 2.0000)
			*counter += make_rrev_rot(&stack_a, &stack_b, param.count);
		stack_a = make_rev_or_rot_a(stack_a, ret, counter, &param);
		stack_b = make_rev_or_rot_b(stack_b, ret, counter, &param);
	/*	printf("\n--------------------------------------\n");
		printf("A : \n");
		print_stk(stack_a);
		printf("B : \n");
		print_stk(stack_b);*/
		stack_a = make_last_step(stack_a, counter, &stack_b);
	}
	return (stack_a);
}

int			is_swap_needed_align(t_stack *stk)
{
	int		len;

	len = ft_stksize(stk);
	while (len-- > 2)
		stk = stk->next;
	len = stk->index;
	stk = stk->next;
	if (len - stk->index >= 1)
		return (1);
	return (0);
}

int		get_moves_b(t_stack	*stk, int pos)
{
	int		n;

	n = ft_stksize(stk);
	if (n < 2 || pos == n - 1)
		return (0);
	if ((double)(pos + 1) < (double)n / 2.000)
		return (pos + 1);
	else
		return (n - (pos + 1));
}

int		get_moves_a(t_stack *stk, int index, int *pos)
{
	int			min;
	int			n;
	int			count;
	t_stack		*next;

	min = index - stk->index;
	*pos = 0;
	count = 0;
	next = stk->next;
	while (next)
	{
		count++;
		n = index - next->index;
		if (abs(min) >= abs(n))
		{
			if (abs(min) != abs(n) || (abs(min) == abs(n) && n > 0))
			{
				*pos = count;
				min = n;
			}
		}
		next = next->next;
	}
	n = get_moves_b(stk, *pos);
	return (n);
}

int		*get_choosen(t_stack *stack_a, t_stack *stack_b, int *ret)
{
	t_stack		*next;
	int			n1;
	int			n2;
	int			pos = 0;
	int			pos_a = -1;

	next = stack_b;
	ret[0] = 2147483647;
	while (next)
	{
		n1 = get_moves_b(stack_b, pos);
		n2 = get_moves_a(stack_a, next->index, &pos_a);
		if (ret[0] > n1 + n2)
		{
			ret[0] = n1 + n2;
			ret[1] = pos;
			ret[2] = pos_a;
		}
		next =  next->next;
		pos++;
	}
	return (ret);
}

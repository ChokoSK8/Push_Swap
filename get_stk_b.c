/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stk_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:06:28 by abrun             #+#    #+#             */
/*   Updated: 2021/04/21 09:36:53 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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

t_stack		*make_push_needed(t_stack *stk, t_stack **stk_b, int *counter, t_meth method)
{
	printf("PUSH\n");
	*counter += 1;
	stk = ft_push(stk_b, &stk);
	clear_keep(stk);
	put_keep(stk, method);
	return (stk);
}

int			make_rrotate_2(t_stack **stack_a, t_stack **stack_b, t_meth *method)
{
	printf("R_ROTATE\n");
	ft_rotate_r(stack_a, stack_b);
	if (is_more_staying(*stack_a))
	{
		*method = get_method(*stack_a);
		clear_keep(*stack_a);
		put_keep(*stack_a, *method);
	}
	return (1);
}

int			make_rrev_rot_2(t_stack **stack_a, t_stack **stack_b, t_meth *method)
{
	if (is_rot_or_rev(*stack_a))
	{
		printf("R_ROTATE\n");
		ft_rotate_r(stack_a, stack_b);
	}
	else
	{
		printf("R-REV-ROTATE\n");
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

t_stack		*make_rot(t_stack *stk, t_meth *method, int *counter)
{
	printf("ROTATE\n");
	*counter += 1;
	stk = ft_rotate(&stk);
	if (is_more_staying(stk))
	{
		*method = get_method(stk);
		clear_keep(stk);
		put_keep(stk, *method);
	}
	return (stk);
}

int			is_swap_needed_b(t_stack *stk)
{
	int		before;

	while (stk->next)
	{
		before = stk->content;
		stk = stk->next;
	}
	if (stk->content < before)
		return (1);
	return (0);
}

int			make_swap_2(t_stack **stk, t_meth method, t_stack **stk_b)
{
	if (*stk_b)
	{
		if (is_swap_needed_b(*stk_b))
		{
			printf("S-SWAP\n");
			ft_sab(stk);
			clear_keep(*stk);
			put_keep(*stk, method);
			ft_sab(stk_b);
		}
		else
		{
			printf("SWAP-A\n");
			ft_sab(stk);
			clear_keep(*stk);
			put_keep(*stk, method);
		}
	}
	else
	{
		printf("SWAP-A\n");
		ft_sab(stk);
		clear_keep(*stk);
		put_keep(*stk, method);
	}
	return (1);
}

t_stacks		get_stack_b(t_stack *stk, int *counter)
{
	t_stack		*stack_b;
	t_stacks	s;
	t_meth		method;

	stack_b = NULL;
	method = get_method(stk);
//	printf("%s : %d from %d\n", method.name, method.nbr, method.from);
	put_keep(stk, method);
	while (is_threw_away(stk))
	{
	/*	printf("\n--------------------------------------\n");
		printf("A : \n");
		print_stk(stk);
		printf("B : \n");
		print_stk(stack_b);*/
		if (is_swap_needed(stk, &method))
			*counter += make_swap_2(&stk, method, &stack_b);
		//	*counter += make_swap(&stk, method);
		else if (is_top_disp(stk))
			stack_b = make_push(&stk, stack_b, counter);
		else
		//	stk = make_rot_or_rev(stk, &method, counter);
		//	stk = make_rot(stk, &method, counter);
			*counter += make_rrev_rot_2(&stk, &stack_b, &method);
	/*	printf("\n--------------------------------------\n");
		printf("A : \n");
		print_stk(stk);
		printf("B : \n");
		print_stk(stack_b);*/
		if (is_push_needed(stk, stack_b, &method))
			stk = make_push_needed(stk, &stack_b, counter, method);
	}
	s.a = stk;
	s.b = stack_b;
	return (s);
}

int			make_swap(t_stack **stk, t_meth method)
{
	printf("SWAP\n");
	ft_sab(stk);
	clear_keep(*stk);
	put_keep(*stk, method);
	return (1);
}

int			get_n_rev_index(t_stack *stk, int index)
{
	int		res;

	res = 0;
	while (stk && stk->index != index)
	{
		stk = stk->next;
		res += 1;
	}
	return (res);
}

t_stack		*make_rot_or_rev_index(t_stack *stk, int index, int *counter)
{
	int		n_rev;
	int		half;
	int		len;

	n_rev = get_n_rev_index(stk, index) + 1;
	len = ft_stksize(stk);
	half = len / 2;
	if (len > 1 && n_rev > 0)
	{
		if (n_rev < half)
		{
			while (n_rev)
			{
				printf("REV-ROT-B\n");
				stk = ft_rev_rot(&stk);
				n_rev--;
				*counter += 1;
			}
		}
		else
		{
			while (n_rev < len)
			{
				printf("ROTATE-B\n");
				stk = ft_rotate(&stk);
				n_rev++;
				*counter += 1;
			}
		}
	}
	return (stk);
}

t_stack		*move_stk_b(t_stack *stk_b, t_stack *stk, int *counter)
{
	int			index;
	int			target;
	t_stack		*next;
	int			n;
	int			min;

	while (stk->next)
		stk = stk->next;
	index = stk->index;
	target = 0;
	next = stk_b;
	min = index - stk_b->index;
	while (next)
	{
		n = index - next->index;
		if (abs(min) >= abs(n) && n > 0)
		{
			target = next->index;
			min = n;
		}
		next = next->next;
	}
	stk_b = make_rot_or_rev_index(stk_b, target, counter);
	return (stk_b);
}

t_stack		*make_push(t_stack **stk, t_stack *stk_b, int *counter)
{
/*	if (stk_b)
		stk_b = move_stk_b(stk_b, *stk, counter);*/
	printf("PUSH\n");
	*counter += 1;
	stk_b = ft_push(stk, &stk_b);
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

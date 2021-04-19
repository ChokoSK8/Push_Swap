/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:40:37 by abrun             #+#    #+#             */
/*   Updated: 2021/04/16 17:01:29 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack		*next;

	printf("A :");
	if (stack_a != NULL)
	{
		next = stack_a->next;
		printf(" %d", stack_a->content);
		while (next)
		{
			printf(" %d", next->content);
			next = next->next;
		}
	}
	printf("\n");
	printf("B :");
	if (stack_b != NULL)
	{
		next = stack_b->next;
		printf(" %d", stack_b->content);
		while (next)
		{
			printf(" %d", next->content);
			next = next->next;
		}
	}
	printf("\n");
}

void		put_index(t_stack *stk)
{
	int			max;
	int			index;
	int			min;
	int			len;
	t_stack		*next;

	max = -2147483648;
	index = 0;
	len = ft_stksize(stk);
	min = 2147483647;
	while (len--)
	{
		next = stk;
		while (next)
		{
			if (next->content < min && next->content > max)
				min = next->content;
			next = next->next;
		}
		next = stk;
		while (next)
		{
			if (next->content == min)
				next->index = index++;
			next = next->next;
		}
		max = min;
		min = 2147483647;
	}
}

t_stack		*get_stack_a(char **av, int ac)
{
	t_stack		*stack;
	int			i;
	t_stack		*first;

	i = 1;
	stack = ft_stknew(ft_atoi(av[i++]));
	first = stack;
	while (i < ac)
	{
		stack->keep = 0;
		stack = ft_stknew(ft_atoi(av[i++]));
		ft_stkadd_back(&first, stack);
	}
	put_index(first);
	return (first);
}

void	clear_buf(char *buf)
{
	int	i;

	i = 0;
	while (i < 5)
		buf[i++] = 0;
}

/*int		check_order(t_stack stack)
{
	int		i;

	i = 0;
	while (i < stack.n - 1)
	{
		if (stack.s[i] > stack.s[i + 1])
			return (0);
		i++;
	}
	return (1);
}*/

int		do_change(t_stack **stack_a, t_stack **stack_b, char *buf)
{
	if (*buf == 's')
		return (ft_s(*stack_a, *stack_b, buf));
	else if (*buf == 'p' && buf[2] == '\n')
	{
		if (buf[1] == 'a')
			*stack_a = ft_push(stack_b, stack_a);
		else if (buf[1] == 'b')
			*stack_b = ft_push(stack_a, stack_b);
		else
			return (0);
		return (1);
	}
	else if (*buf == 'r')
		{
			if (buf[1] == 'r' && buf[2] != '\n')
				return (ft_rr(stack_a, stack_b, buf));
			else
				return (ft_r(stack_a, stack_b, buf));
		}
	else
		return (0);
}

int		start_checker(t_stack *stack_a)
{
	char		buf[5];
	t_stack		*stack_b;

	read(1, buf, 4);
	stack_b = NULL;
	while (*buf != '\n')
	{
		if (!do_change(&stack_a, &stack_b, buf))
		{
			printf("Mauvaise instruction !\n");
			return (0);
		}
		clear_buf(buf);
		print_stacks(stack_a, stack_b);
		read(1, buf, 4);
	}
	return (1);
}

t_meth		get_greater_head(t_stack *stack)
{
	int			n;
	t_stack		*next;
	int			head;
	t_meth		great;
	int			ret;

	head = 0;
	great.from = ft_stksize(stack);
	while (stack)
	{
		n = 1;
		great.nbr = stack->index;
		ret = stack->content;
		next = stack->next;
		while (next)
		{
			if (ret < next->content)
			{
				ret = next->content;
				n++;
			}
			next = next->next;
		}
		if (head == n && great.nbr < great.from)
			great.from = great.nbr;
		if (head < n)
		{
			great.from = great.nbr;
			head = n;
		}
		stack = stack->next;
		if (next)
			next = next->next;
	}
	great.nbr = head;
	return (great);
}

t_meth		get_index_head(t_stack *stk)
{
	int			n;
	t_stack		*next;
	int			len;
	int			head;
	t_stack		*cur;
	t_meth		index;

	len = ft_stksize(stk);
	head = 0;
	index.from = len - 1;
	while (len--)
	{
		n = 1;
		cur = stk;
		next = cur->next;
		index.nbr = stk->index;
		while (next)
		{
			if (cur->index == next->index - 1)
			{
				cur = next;
				n++;
			}
			next = next->next;
		}
		if (head == n && index.nbr < index.from)
			index.from = index.nbr;
		if (head < n)
		{
			index.from = index.nbr;
			head = n;
		}
		stk = stk->next;
	}
	index.nbr = head;
	return (index);
}

void	print_stk(t_stack *stk)
{
	t_stack		*next;

	next = stk;
	while (next)
	{
		if (next->content >= 0)
			printf("      %d [%d] --> %d\n", next->content, next->index, next->keep);
		else
			printf("     %d [%d] --> %d\n", next->content, next->index, next->keep);
		next = next->next;
	}
}

t_meth		get_method(t_stack *stk)
{
	t_meth		index;
	t_meth		great;

	index = get_index_head(stk);
	great = get_greater_head(stk);
	index.name = "index";
	great.name = "great";
	if (index.nbr == great.nbr)
	{
		if (index.from <= great.from)
			return (index);
		else
			return (great);
	}
	if (great.nbr > index.nbr)
		return (great);
	else
		return (index);
}

void		put_keep(t_stack *stk, t_meth method)
{
	t_stack		*curr;
	int			ret;

	while (method.from != stk->index)
		stk = stk->next;
	stk->keep = 1;
	if (!ft_strncmp(method.name, "great", 5))
	{
		ret = stk->content;
		while (stk->next)
		{
			curr = stk;
			stk = stk->next;
			if (stk->content > ret)
			{
				stk->keep = 1;
				ret = stk->content;
			}
		}
	}
	else
	{
		ret = stk->index;
		while (stk->next)
		{
			stk = stk->next;
			if (stk->index == ret + 1)
			{
				ret = stk->index;
				stk->keep = 1;
			}
		}
	}
}

void		clear_keep(t_stack *stk)
{
	while (stk)
	{
		stk->keep = 0;
		stk = stk->next;
	}
}

t_stack		*duplicate_stk(t_stack *stk)
{
	t_stack		*clone;
	t_stack		*first;

	clone = ft_stknew(stk->content);
	clone->keep = 0;
	clone->index = stk->index;
	first = clone;
	while (stk->next)
	{
		stk = stk->next;
		clone = ft_stknew(stk->content);
		clone->keep = 0;
		clone->index = stk->index;
		ft_stkadd_back(&first, clone);
	}
	return (first);
}

void		free_tmp(t_stack **tmp)
{
	t_stack		*next;

	while (*tmp)
	{
		next = (*tmp)->next;
		free(*tmp);
		*tmp = next;
	}
	*tmp = 0;
	free(next);
}

void		print_tmp(t_stack *tmp)
{
	printf("TMP : \n");
	while (tmp)
	{
		printf("%d [%d]\n", tmp->content, tmp->index);
		tmp = tmp->next;
	}
}

int			is_swap_needed(t_stack *stk, t_meth *method)
{
	t_stack		*tmp;
	t_meth		toad;

	tmp = duplicate_stk(stk);
	if (ft_stksize(stk) > 2)
	{
		clear_keep(tmp);
		ft_swap(tmp);
		toad = get_method(tmp);
		if (toad.nbr > method->nbr)
		{
			method->nbr = toad.nbr;
			method->name = toad.name;
			method->from = toad.from;
			free_tmp(&tmp);
			return (1);
		}
	}
	free_tmp(&tmp);
	return (0);
}

int			is_top_disp(t_stack *stk)
{
	while (stk->next)
		stk = stk->next;
	if (stk->keep == 0)
		return (1);
	return (0);
}

int			is_threw_away(t_stack *stk)
{
	while (stk)
	{
		if (stk->keep == 0)
			return (1);
		stk = stk->next;
	}
	return (0);
}

int				is_rot_or_rev(t_stack *stk)
{
	int			n_rev;
	int			n_rot;

	n_rev = 1;
	while (stk->keep == 1)
	{
		stk = stk->next;
		n_rev++;
	}
	n_rot = 0;
	while (stk)
	{
		while (stk && stk->keep == 1)
		{
			stk = stk->next;
			n_rot++;
		}
		if (stk)
		{
			stk = stk->next;
			n_rot = 1;
		}
	}
//	printf("rev : %d\nrot : %d\n", n_rev, n_rot);
	if (n_rev < n_rot)
		return (0);
	return (1);
}

int				count_keep(t_stack *stk)
{
	int		n;

	n = 0;
	while (stk)
	{
		if (stk->keep == 1)
			n++;
		stk = stk->next;
	}
	return (n);
}

int				is_more_staying(t_stack *stk)
{
	t_stack		*tmp;
	t_meth		method;
	int			n_stk;
	int			n_tmp;

	tmp = duplicate_stk(stk);
	method = get_method(stk);
	clear_keep(tmp);
	put_keep(tmp, method);
	n_stk = count_keep(stk);
	n_tmp = count_keep(tmp);
	if (n_stk >= n_tmp)
		return (0);
	return (1);
}

t_stacks		get_stack_b(t_stack *stk, int *counter)
{
	t_stack		*stack_b;
	t_stacks	s;
	t_meth		method;

	stack_b = NULL;
	method = get_method(stk);
	put_keep(stk, method);
	printf("%s : %d stay from %d\n", method.name, method.nbr, method.from);
	printf("A : -->\n");
	print_stk(stk);
	printf("B : -->\n");
	print_stk(stack_b);
	while (is_threw_away(stk))
	{
		if (is_swap_needed(stk, &method))
		{
			printf("SWAP\n");
			*counter += 1;
			ft_sab(stk);
			clear_keep(stk);
		//	printf("%s : %d stay from %d\n", method.name, method.nbr, method.from);
			put_keep(stk, method);
		}
		else if (is_top_disp(stk))
		{
			printf("PUSH\n");
			*counter += 1;
			stack_b = (ft_push(&stk, &stack_b));
		}
		else
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
				method = get_method(stk);
				clear_keep(stk);
				put_keep(stk, method);
			}
		}
	//	printf("A : -->\n");
	//	print_stk(stk);
	//	printf("B : -->\n");
	//	print_stk(stack_b);
	}
	s.a = stk;
	s.b = stack_b;
	return (s);
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
	//	printf("n1 : %d\nn2 : %d\n", n1, n2);
		if (ret[0] > (n1 + n2))
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

int			is_align(t_stack *stk)
{
	t_stack		*next;
	int			cur;

	next = stk;
	while (next->next)
	{
		cur = next->content;
		next = next->next;
		if (cur > next->content)
			return (0);
	}
	return (1);
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

t_stack		*align_stack_a(t_stack *stk, int *counter)
{
	t_meth		method;

	method = get_method(stk);
	put_keep(stk, method);
	printf("\n***********************************\n");
	printf("A : -->\n");
	print_stk(stk);
	while (!is_align(stk))
	{
	/*	if (is_swap_needed_align(stk))
		{
			printf("SWAP\n");
			ft_sab(stk);
			method = get_method(stk);
			clear_keep(stk);
			put_keep(stk, method);
		}*/
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
				method = get_method(stk);
				clear_keep(stk);
				put_keep(stk, method);

	//	printf("A : -->\n");
	//	print_stk(stk);
	}
	return (stk);
}

int		main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stacks	s;
	int			counter = 0;

	if (ac < 2)
		return (0);
	stack_a = get_stack_a(av, ac);
	s = get_stack_b(stack_a, &counter);
	stack_a = s.a;
	stack_b = s.b;
	printf("A : -->\n");
	print_stk(stack_a);
	printf("\n---------------------------------------------------\n");
	printf("A : -->\n");
	print_stk(stack_a);
	printf("B : -->\n");
	print_stk(stack_b);
	

	double		len_a;
	double		len_b;
	int			count_a;
	int			count_b;
	int			size_b;
	int			*ret;

	if (!(ret = malloc(sizeof(int) * 3)))
		return (0);
	size_b = ft_stksize(stack_b);
	while (size_b--)
	{
		get_choosen(stack_a, stack_b, ret);
		len_a = ft_stksize(stack_a);
		len_b = ft_stksize(stack_b);
	//	printf("On push %d, et on move %d\n", ret[1], ret[2]);
		count_a = get_moves_b(stack_a, ret[2]);
		count_b = get_moves_b(stack_b, ret[1]);
		if ((double)(ret[2] + 1) >= len_a / 2.0000 && (double)(ret[1] + 1) >= len_b / 2.0000)
		{
			while (count_a > 0 && count_b > 0)
			{
				printf("R-ROTATE\n");
				counter += 1;
				ft_rotate_r(&stack_a, &stack_b);
				count_a--;
				count_b--;
			}
		}
		else if ((double)(ret[2] + 1) < len_a / 2.0000 && (double)(ret[1] + 1) < len_b / 2.0000)
		{
			while (count_a > 0 && count_b > 0)
			{
				printf("R-REV-ROTATE\n");
				counter += 1;
				ft_rev_rot_r(&stack_a, &stack_b);
				count_a--;
				count_b--;
			}
		}
		if ((double)(ret[2] + 1) >= len_a / 2.0000)
		{
			while (count_a--)
			{
				printf("ROTATE_a\n");
				counter += 1;
				stack_a = ft_rotate(&stack_a);
			}
		}
		else
		{
			while (count_a--)
			{
				printf("REV-ROTATE_a\n");
				counter += 1;
				stack_a = ft_rev_rot(&stack_a);
			}
		}
		if ((double)(ret[1] + 1) >= len_b / 2.0000)
		{
			while (count_b-- > 0)
			{
				printf("ROTATE_b\n");
				counter += 1;
				stack_b = ft_rotate(&stack_b);
			}
		}
		else
		{
			while (count_b-- > 0)
			{
				printf("REV-ROTATE_b\n");
				counter += 1;
				stack_b = ft_rev_rot(&stack_b);
			}
		}
		printf("PUSH_A\n");
		stack_a = ft_push(&stack_b, &stack_a);
		if (is_swap_needed_align(stack_a))
		{
			printf("SWAP\n");
			counter += 1;
			ft_sab(stack_a);
		}
//		printf("\n---------------------------------------------------\n");
//		printf("A : -->\n");
//		print_stk(stack_a);
//		printf("B : -->\n");
//		print_stk(stack_b);
	}
	stack_a = align_stack_a(stack_a, &counter);
	printf("\n---------------------------------------------------\n");
	printf("A : -->\n");
	print_stk(stack_a);
	printf("Trié en %d opérations\n", counter);
	return (1);
}

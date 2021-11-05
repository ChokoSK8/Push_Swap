/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stk_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:58:08 by abrun             #+#    #+#             */
/*   Updated: 2021/11/05 14:19:16 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stack	*get_stack_a(char **av, int ac)
{
	t_stack		*stack;
	int			i;
	t_stack		*first;

	i = 1;
	first = NULL;
	while (i < ac)
	{
		if (!check_av(av[i]))
		{
			ft_putstr_fd(2, "Error\n");
			ft_stkclear(&first);
			return (0);
		}
		first = create_stack(av[i], first);
		if (!first)
			return (0);
		i++;
	}
	put_index(first);
	return (first);
}

t_stack	*create_stack(char *av, t_stack *first)
{
	char		**split;
	t_stack		*stk;
	int			n;
	int			counter;

	split = ft_split(av, 32);
	counter = 0;
	while (split[counter])
	{
		n = ft_atoi(split[counter]);
		if (!check_digit_int(split[counter++]))
			return (exit_get_stk_a(first, split));
		stk = ft_stknew((int)n);
		if (!stk)
			return (exit_get_stk_a(first, split));
		ft_stkadd_back(&first, stk);
		stk->keep = 0;
	}
	free_matc(split);
	return (first);
}

t_stack	*exit_get_stk_a(t_stack *first, char **split)
{
	ft_stkclear(&first);
	free_matc(split);
	ft_putstr_fd(2, "Error\n");
	return (0);
}

void	put_index(t_stack *stk)
{
	int			index;
	long long	min;
	int			len;
	t_stack		*next;

	index = 0;
	len = ft_stksize(stk);
	min = -2147483649;
	while (len--)
	{
		next = stk;
		min = get_min(next, min);
		while (next)
		{
			if ((long long)next->content == min)
				next->index = index++;
			next = next->next;
		}
	}
}

void	put_keep(t_stack *stk, t_meth method)
{
	while (method.from != stk->index)
		stk = stk->next;
	stk->keep = 1;
	if (!ft_strncmp(method.name, "great", 5))
		stk = put_keep_great(stk);
	else
		stk = put_keep_index(stk);
}

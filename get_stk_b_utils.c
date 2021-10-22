/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stk_b_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:38:23 by abrun             #+#    #+#             */
/*   Updated: 2021/10/22 19:24:17 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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

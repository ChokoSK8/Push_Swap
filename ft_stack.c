/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:06:54 by abrun             #+#    #+#             */
/*   Updated: 2021/04/21 11:18:09 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stack		*ft_stknew(int content)
{
	t_stack		*stknew;

	if (!(stknew = malloc((sizeof(t_stack)))))
		return (0);
	stknew->content = content;
	stknew->next = NULL;
	return (stknew);
}

void		ft_stkadd_back(t_stack **astk, t_stack *new)
{
	t_stack		*last;

	last = ft_stklast(*astk);
	if (last)
		last->next = new;
	else
		*astk = new;
}

t_stack		*ft_stklast(t_stack *stk)
{
	t_stack		*next;

	if (stk == NULL)
		return (0);
	next = stk->next;
	while (next)
	{
		stk = next;
		next = stk->next;
	}
	return (stk);
}

int			ft_stksize(t_stack *stk)
{
	int	lenght;

	lenght = 0;
	while (stk)
	{
		lenght++;
		stk = stk->next;
	}
	return (lenght);
}

void		ft_stkremove_last(t_stack **stk)
{
	int			n;
	t_stack		*next;
	t_stack		*s;

	s = *stk;
	next = s->next;
	n = ft_stksize(*stk);
	if (n == 2)
		s->next = NULL;
	else if (n == 1)
		*stk = NULL;
	else
	{
		while (--n > 2)
			next = next->next;
		next->next = NULL;
	}
}

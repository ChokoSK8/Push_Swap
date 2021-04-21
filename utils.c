/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 09:50:51 by abrun             #+#    #+#             */
/*   Updated: 2021/04/21 12:30:30 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void		print_stk(t_stack *stk)
{
	t_stack		*next;

	next = stk;
	while (next)
	{
		if (next->content >= 0)
			printf("      %d [%d] --> %d\n", next->content,
				next->index, next->keep);
		else
			printf("     %d [%d] --> %d\n", next->content,
				next->index, next->keep);
		next = next->next;
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

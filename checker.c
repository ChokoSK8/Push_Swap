/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 11:35:13 by abrun             #+#    #+#             */
/*   Updated: 2021/04/19 11:39:26 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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

void	clear_buf(char *buf)
{
	int	i;

	i = 0;
	while (i < 5)
		buf[i++] = 0;
}

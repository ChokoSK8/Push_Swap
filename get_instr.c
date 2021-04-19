/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:06:58 by abrun             #+#    #+#             */
/*   Updated: 2021/04/13 16:47:34 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		ft_s(t_stack *stack_a, t_stack *stack_b, char *buf)
{
	if (buf[2] == '\n')
	{
		if (buf[1] == 'a')
		{
			ft_sab(stack_a);
			return (1);
		}
		else if (buf[1] == 'b')
		{
			ft_sab(stack_b);
			return (1);
		}
		else if (buf[1] == 's')
		{
			ft_ss(stack_a, stack_b);
			return (1);
		}
	}
	return (0);
}

/*int		ft_p(t_stack *stack_a, t_stack *stack_b, char *buf)
{
	if (buf[2] == '\n')
	{
		if (buf[1] == 'a')
		{
			stack_a = ft_push(stack_b, stack_a);
			return (1);
		}
		else if (buf[1] == 'b')
		{
			stack_b = ft_push(stack_a, stack_b);
			print_stacks(stack_a, stack_b);
			return (1);
		}
	}
	return (0);
}*/

int		ft_r(t_stack **stack_a, t_stack **stack_b, char *buf)
{
	if (buf[2] == '\n')
	{
		if (buf[1] == 'a')
		{
			*stack_a = ft_rotate(stack_a);
			return (1);
		}
		else if (buf[1] == 'b')
		{
			*stack_b = ft_rotate(stack_b);
			return (1);
		}
		else if (buf[1] == 'r')
		{
			ft_rotate_r(stack_a, stack_b);
			return (1);
		}
	}
	return (0);
}

int		ft_rr(t_stack **stack_a, t_stack **stack_b, char *buf)
{
	if (buf[3] == '\n')
	{
		if (buf[2] == 'a')
		{
			*stack_a = ft_rev_rot(stack_a);
			return (1);
		}
		else if (buf[2] == 'b')
		{
			*stack_b = ft_rev_rot(stack_b);
			return (1);
		}
		else if (buf[2] == 'r')
		{
			ft_rev_rot_r(stack_a, stack_b);
			return (1);
		}
	}
	return (0);
}

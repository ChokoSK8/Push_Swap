/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:40:37 by abrun             #+#    #+#             */
/*   Updated: 2021/10/26 18:05:44 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stacks	s;

	if (ac < 2)
		return (1);
	stack_a = get_stack_a(av, ac);
	if (!stack_a || is_doublon(stack_a))
		return (1);
	if (ft_stksize(stack_a) <= 5)
		s = get_stack_b_5(stack_a);
	else
		s = get_stack_b(stack_a);
	stack_b = s.b;
	stack_a = s.a;
	stack_a = move_b_to_a(stack_a, stack_b);
	stack_a = align_stack_a(stack_a);
	ft_stkclear(&stack_a);
	return (0);
}

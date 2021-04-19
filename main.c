/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:40:37 by abrun             #+#    #+#             */
/*   Updated: 2021/04/19 11:40:32 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

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
	printf("counter : %d\n", counter);
	stack_a = s.a;
	stack_b = s.b;
	printf("A : -->\n");
	print_stk(stack_a);
	printf("\n---------------------------------------------------\n");
	printf("A : -->\n");
	print_stk(stack_a);
	printf("B : -->\n");
	print_stk(stack_b);
	
	stack_a = move_b_to_a(stack_a, stack_b, &counter);
	printf("counter : %d\n", counter);

	stack_a = align_stack_a(stack_a, &counter);
	printf("counter : %d\n", counter);
	printf("\n---------------------------------------------------\n");
	printf("A : -->\n");
	print_stk(stack_a);
	printf("Trié en %d opérations\n", counter);
	return (1);
}

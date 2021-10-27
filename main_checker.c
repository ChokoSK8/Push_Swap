/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:41:57 by abrun             #+#    #+#             */
/*   Updated: 2021/10/27 12:13:12 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int ac, char **av)
{
	t_stack		*stack_a;

	if (ac < 2)
		return (0);
	stack_a = get_stack_a(av, ac);
	if (!stack_a || is_doublon(stack_a))
		return (1);
	start_checker(stack_a);
	ft_stkclear(&stack_a);
	return (0);
}

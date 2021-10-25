/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:41:57 by abrun             #+#    #+#             */
/*   Updated: 2021/10/25 18:04:52 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	int			ret;

	if (ac < 2)
		return (0);
	stack_a = get_stack_a(av, ac);
	ret = start_checker(stack_a);
	return (ret);
}

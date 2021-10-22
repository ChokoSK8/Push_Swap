/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:40:17 by abrun             #+#    #+#             */
/*   Updated: 2021/10/22 19:05:30 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int			is_same_command(t_stack *stk_a, t_stack *stk_b,
		int pos_b, int pos_a)
{
	int		len_a;
	int		len_b;
	int		rot_a;
	int		rot_b;

	len_a = ft_stksize(stk_a);
	len_b = ft_stksize(stk_b);
	if (!(len_a % 2))
	{
		if (len_a < 2 || (double)(pos_a + 1) <= (double)len_a / 2.000)
			rot_a = 0;
		else
			rot_a = 1;
	}
	else
	{
		if (len_a < 2 || (double)(pos_a + 1) <= ((double)len_a / 2.000) + 1)
			rot_a = 0;
		else
			rot_a = 1;
	}
	if (!(len_b % 2))
	{	
		if (len_b < 2 || (double)(pos_b + 1) <= (double)len_b / 2.000)
			rot_b = 0;
		else
			rot_b = 1;
	}
	else
	{	
		if (len_b < 2 || (double)(pos_b + 1) <= ((double)len_b / 2.000) + 1)
			rot_b = 0;
		else
			rot_b = 1;
	}
	if (rot_a == rot_b)
		return (1);
	return (0);
}

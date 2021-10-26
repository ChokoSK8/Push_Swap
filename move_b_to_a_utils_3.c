/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a_utils_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:20:45 by abrun             #+#    #+#             */
/*   Updated: 2021/10/26 19:08:05 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	get_rot(int pos, int len)
{
	int	rot;

	if (!(len % 2))
	{
		if (len < 2 || (double)(pos + 1) <= (double)len / 2.000)
			rot = 0;
		else
			rot = 1;
	}
	else
	{
		if (len < 2 || (double)(pos + 1) <= ((double)len / 2.000) + 1)
			rot = 0;
		else
			rot = 1;
	}
	return (rot);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	is_rrotate_ok(int *ret, t_param param)
{
	int	rot_a;
	int	rot_b;

	rot_a = get_rot(ret[2], param.len[0]);
	rot_b = get_rot(ret[1], param.len[1]);
	if (rot_a != rot_b)
		return (0);
	if (rot_a == 0)
		return (1);
	return (0);
}

int	is_rrev_ok(int *ret, t_param param)
{
	int	rot_a;
	int	rot_b;

	rot_a = get_rot(ret[2], param.len[0]);
	rot_b = get_rot(ret[1], param.len[1]);
	if (rot_a != rot_b)
		return (0);
	if (rot_a == 1)
		return (1);
	return (0);
}

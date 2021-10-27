/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:33:04 by abrun             #+#    #+#             */
/*   Updated: 2021/10/27 14:43:58 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	check_digit_int(char *digit)
{
	size_t		digit_len;

	digit_len = ft_strlen(digit);
	if (digit_len < 10)
		return (1);
	if (digit_len >= 12)
		return (0);
	if (digit_len == 12 && *digit != '-')
		return (0);
	if (digit_len == 11 && ft_strncmp(digit, "-2147483648", 11) > 0)
		return (0);
	if (digit_len == 10 && ft_strncmp(digit, "2147483647", 10) > 0)
		return (0);
	return (1);
}

int	check_av(char *av)
{
	int	counter;

	counter = 0;
	while (av[counter] && av[counter + 1])
	{
		if (ft_is_sign_digit(av[counter], av[counter + 1]) || av[counter] == 32)
			counter++;
		else
			return (0);
	}
	if (ft_isdigit(av[counter]) || av[counter] == 32)
		return (1);
	return (0);
}

int	is_doublon(t_stack *stk)
{
	t_stack	*first;
	t_stack	*tmp;

	first = stk;
	while (stk)
	{
		tmp = stk->next;
		while (tmp)
		{
			if (tmp->content == stk->content)
			{
				ft_stkclear(&first);
				ft_putstr_fd(2, "Error\n");
				return (1);
			}
			tmp = tmp->next;
		}
		stk = stk->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:58:21 by abrun             #+#    #+#             */
/*   Updated: 2021/04/16 09:43:57 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_H

#define PUSH_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "Libft/libft.h"

typedef struct	s_stack
{
	int					content;
	int					index;
	struct s_stack		*next;
	int					keep;
}				t_stack;

typedef struct	s_stacks
{
	t_stack		*a;
	t_stack		*b;
}				t_stacks;

typedef struct	s_meth
{
	char	*name;
	int		nbr;
	int		from;
}				t_meth;

t_stack			*ft_stklast(t_stack *stk);

void			ft_stkadd_back(t_stack **astk, t_stack *new);

t_stack			*ft_stknew(int content);

int				ft_stksize(t_stack *stk);

void			ft_stkremove_last(t_stack **stk);

void			ft_stkadd_front(t_stack **astk, t_stack *new);

int				ft_rr(t_stack **stack_a, t_stack **stack_b, char *buf);

int				ft_r(t_stack **stack_a, t_stack **stack_b, char *buf);

int				ft_rotate_r(t_stack **stack_a, t_stack **stack_b);

int				ft_rev_rot_r(t_stack **stack_a, t_stack **stack_b);

int				ft_p(t_stack *stack_a, t_stack *stack_b, char *buf);

int				ft_s(t_stack *stack_a, t_stack *stack_b, char *buf);

int				ft_ss(t_stack *stack_a, t_stack *stack_b);

int				ft_sab(t_stack *stack);

void			ft_swap(t_stack *stk);

t_stack			*ft_rev_rot(t_stack **stack);

t_stack			*ft_push(t_stack **put, t_stack **rec);

t_stack			*ft_rotate(t_stack **stk);

void			print_stacks(t_stack *a, t_stack *b);
#endif 

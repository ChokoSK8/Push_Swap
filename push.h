/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:58:21 by abrun             #+#    #+#             */
/*   Updated: 2021/11/05 14:02:06 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

typedef struct s_stack
{
	int					content;
	int					index;
	struct s_stack		*next;
	int					keep;
}				t_stack;

typedef struct s_param
{
	double		len[2];
	int			count[2];
}				t_param;

typedef struct s_stacks
{
	t_stack		*a;
	t_stack		*b;
}				t_stacks;

typedef struct s_meth
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

int				ft_s(t_stack **stack_a, t_stack **stack_b, char *buf);

int				ft_ss(t_stack *stack_a, t_stack *stack_b);

void			ft_swap(t_stack **stk);

t_stack			*ft_rev_rot(t_stack **stack);

t_stack			*ft_push(t_stack **put, t_stack **rec);

t_stack			*ft_rotate(t_stack **stk);

void			print_stacks(t_stack *a, t_stack *b);

void			print_stk(t_stack *stk);

t_stacks		get_stack_b(t_stack *stk);

void			put_index(t_stack *stk);

void			put_keep(t_stack *stk, t_meth method);

t_stack			*get_stack_a(char **av, int ac);

t_meth			get_index_head(t_stack *stk);

t_meth			get_greater_head(t_stack *stack);

t_meth			get_method(t_stack *stk);

void			put_keep(t_stack *stk, t_meth method);

void			clear_keep(t_stack *stk);

int				is_threw_away(t_stack *stk);

int				is_swap_needed(t_stack *stk, t_meth *meth);

int				is_top_disp(t_stack *stk);

int				is_rot_or_rev(t_stack *stk);

int				is_more_staying(t_stack *stk);

int				is_align(t_stack *stk);

t_stack			*align_stack_a(t_stack *stk);

int				is_swap_needed_align(t_stack *stk);

t_stack			*move_b_to_a(t_stack *stk, t_stack *stk_b);

int				*get_choosen(t_stack *stack_a, t_stack *stack_b, int *ret);

int				get_moves_a(t_stack *stk, int index, int *pos);

int				get_moves_b(t_stack	*stk, int pos);

int				is_more_staying(t_stack *stk);

int				is_rot_or_rev(t_stack *stk);

int				is_rot_or_rev_align(t_stack *stk);

int				is_threw_away(t_stack *stk);

int				is_top_disp(t_stack *stk);

int				is_swap_needed(t_stack *stk, t_meth *method);

t_stack			*duplicate_stk(t_stack *stk);

void			free_tmp(t_stack **tmp);

int				count_keep(t_stack *stk);

int				do_change(t_stack **stack_a, t_stack **stack_b, char *buf);

int				start_checker(t_stack *stack_a);

void			clear_keep(t_stack *stk);

void			clear_buf(char *buf);

int				get_n_rev(t_stack *stk);

int				get_n_greater(t_stack *stk, int ret);

int				get_n_index(t_stack *stk, int ret);

long long		get_min(t_stack *stk, long long max);

int				get_max(t_stack *stk, int min);

t_stack			*put_keep_great(t_stack *stk);

t_stack			*put_keep_index(t_stack *stk);

int				make_swap(t_stack **stk, t_meth method);

t_stack			*make_push(t_stack **stk, t_stack *stk_b);

t_stack			*make_rot_or_rev(t_stack *stk, t_meth *method);

int				make_rrotate(t_stack **stk_a, t_stack **stk_b, int *count);

int				make_rrev_rot(t_stack **stk_a, t_stack **stk_b, int *count);

t_stack			*make_rev_or_rot_a(t_stack *stk, int *ret, t_param *param);

t_stack			*make_rev_or_rot_b(t_stack *stk, int *ret, t_param *param);

t_stack			*make_last_step(t_stack *stk_a, t_stack **stk_b);

int				is_swap_needed_b(t_stack *stk);

int				start_checker(t_stack *stk);

int				make_swap_2(t_stack **stk_a, t_meth method, t_stack **stk_b);

int				make_rrev_rot_2(t_stack **stk_a, t_stack **stk_b,
					t_meth *method);

int				is_push_needed(t_stack *stk_a, t_stack *stk_b, t_meth *method);

t_stack			*make_push_needed(t_stack *stk_a, t_stack **stk_b,
					t_meth method);

int				is_same_command(t_stack *stack_a, t_stack *stack_b,
					int pos, int pos_a);

int				ft_isdigit(char c);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

int				ft_atoi(const char *str);

void			ft_stkclear(t_stack **stk);

t_stack			*make_ra_rra_pair(t_stack *stk, int *ret, t_param *param);

t_stack			*make_ra_rra_odd(t_stack *stk, int *ret, t_param *param);

t_stack			*make_rb_rrb_pair(t_stack *stk, int *ret, t_param *param);

t_stack			*make_rb_rrb_odd(t_stack *stk, int *ret, t_param *param);

int				get_rot(int pos, int len);

int				ft_max(int a, int b);

t_stacks		get_stack_b_5(t_stack *stk_a);

t_stack			*sort_stk_a_3(t_stack *stk);

int				is_sorted_3(t_stack *stk);

int				is_doublon(t_stack *stk);

void			ft_putstr_fd(int fd, char *str);

t_stack			*create_stack(char *av, t_stack *first);

char			**ft_split(char *s, char c);

void			free_matc(char **matc);

int				check_av(char *av);

int				ft_is_sign_digit(char *s, int c);

int				check_digit_int(char *digit);

size_t			ft_strlen(char *s);

int				is_rrev_ok(int *ret, t_param param);

int				is_rrotate_ok(int *ret, t_param param);

t_stack			*exit_get_stk_a(t_stack *first, char **split);
#endif 

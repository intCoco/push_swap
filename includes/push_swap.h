/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:36:11 by chuchard          #+#    #+#             */
/*   Updated: 2023/04/05 18:53:32 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# define A 'a'
# define B 'b'

typedef struct s_stack
{
	int 	*array;
	int		size;
	struct s_stack	*other;
	int		max;
	int		min;
}	t_stack;

typedef struct s_prog
{
	t_stack a;
	t_stack b;
	int		*sorted;
	int		max;
	int		min;
	int		size;
	int		chunk_nb;
}	t_prog;

void	ft_rot(t_stack *stack, char c);
void	ft_rev_rot(t_stack *stack, char c);
void	ft_swap(t_stack *stack, char c);
void	ft_push(t_stack *stack, char c);
int		ft_psw_atoi(t_prog *pg, char *str);
void	convert(t_prog *pg, int ac, char **av);
void	ft_exit(t_prog *pg, int c);
void	sort_tab(t_prog *pg);
void	ft_char_check(int ac, char **av);
void	ft_issorted(t_prog *pg);
void	ft_double_check(t_prog *pg);
int		ft_find_min_idx(t_stack stack);
int		ft_find_max_idx(t_stack stack);
int		find_closest_min(t_prog pg, t_stack stack, int chunk);
void	ft_top_and_push(t_stack *stack, int i, char c);

void	ft_print_stacks(t_prog pg);

#endif

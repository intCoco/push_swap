/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:36:11 by chuchard          #+#    #+#             */
/*   Updated: 2023/03/07 12:18:36 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int *array;
	int	size;
}	t_stack;

typedef struct s_prog
{
	t_stack a;
	t_stack b;
}	t_prog;

void	ft_push(t_stack *src, t_stack *dest);
void	ft_rot(t_stack *stack);
void	ft_rev_rot(t_stack *stack);
void	ft_swap(t_stack *stack);

#endif

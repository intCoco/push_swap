/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:22:42 by chuchard          #+#    #+#             */
/*   Updated: 2023/03/07 17:22:18 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *src, t_stack *dest, char c)
{
	int	i;
	int	tmp;
	
	if (!src)
		return ;
	i = 0;
	tmp = src->array[0];
	while (++i < dest->size + 1)
		dest->array[i] = dest->array[i - 1];
	dest->size++;
	dest->array[0] = tmp;
	i = -1;
	while (++i < src->size - 1)
		src->array[i] = src->array[i + 1];
	src->size--;
	ft_printf("p%c\n", c);
}

void	ft_rot(t_stack *stack, char c)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->array[0];
	i = -1;
	while (++i < stack->size - 1)
		stack->array[i] = stack->array[i + 1];
	stack->array[++i] = tmp;
	ft_printf("r%c\n", c);
}

void	ft_rev_rot(t_stack *stack, char c)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	i = stack->size;
	tmp = stack->array[i - 1];
	while (--i > 0)
		stack->array[i] = stack->array[i - 1];
	stack->array[0] = tmp;
	ft_printf("rr%c\n", c);
}

void	ft_swap(t_stack *stack)
{
	int	tmp;
	
	if (stack->size < 2)
		return ;
	tmp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = tmp;
}

/*void	ft_rot(t_link *stack)
{
	int	top;

	top = stack->value;
	while (stack->next)
	{
		stack->value = stack->next->value;
		stack = stack->next;
	}
	stack->value = top;
}*/

/*void	ft_push(t_link *src_top, t_link *dest_top)
{
	t_link *next;

	if (src_top)
	{
		next = src_top->next;
		ft_lstadd_front(dest_top, src_top);
		*src_top = *next;
	}
}*/

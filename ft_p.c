/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:22:42 by chuchard          #+#    #+#             */
/*   Updated: 2023/02/02 21:11:42 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_link *src_top, t_link *dest_top)
{
	t_link *next;

	if (src_top)
	{
		next = src_top->next;
		ft_lstadd_front(dest_top, src_top);
		*src_top = *next;
	}
}

void	ft_rot(t_link *stack)
{
	t_link	*next;
	t_link	*top;
	int		top;

	top = stack->value;
	while (stack->next)
	{
		stack->value = stack->next->value;
	}
	top->next = NULL;
	next = stack->next;
	stack->next = NULL;
	ft_lstadd_back(stack, top);
	*stack = *next;
}


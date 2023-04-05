/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:58:59 by chuchard          #+#    #+#             */
/*   Updated: 2023/04/05 18:20:44 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_min_idx(t_stack stack)
{
	int	i;
	int	idx;
	int	min;

	i = 0;
	idx = 0;
	min = stack.array[0];
	while (i < stack.size)
	{
		if (min > stack.array[i])
		{
			min = stack.array[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

int	ft_find_max_idx(t_stack stack)
{
	int	i;
	int	idx;
	int	max;

	i = 0;
	idx = 0;
	max = stack.array[0];
	while (i < stack.size)
	{
		if (max < stack.array[i])
		{
			max = stack.array[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

int	find_closest_min(t_prog pg, t_stack stack, int chunk)
{
	int	i;
	int	from_top;
	int	from_bot;

	i = 0;
	from_top = -1;
	from_bot = -1;
	while (i++ < stack.size && from_top == -1)
		if (stack.array[i] >= pg.sorted[pg.size / pg.chunk_nb * (chunk - 1)]
			&& (stack.array[i] <= pg.sorted[pg.size / pg.chunk_nb * chunk]
				|| chunk == pg.chunk_nb))
			from_top = i;
	i = stack.size - 1;
	while (i-- >= 0 && from_bot == -1)
		if (stack.array[i] >= pg.sorted[pg.size / pg.chunk_nb * (chunk - 1)]
			&& (stack.array[i] <= pg.sorted[pg.size / pg.chunk_nb * chunk]
				|| chunk == pg.chunk_nb))
			from_bot = i;
	if (from_top <= pg.size - from_bot)
		return (from_top);
	else
		return (from_bot);
}
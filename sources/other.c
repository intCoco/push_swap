/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:00:56 by chuchard          #+#    #+#             */
/*   Updated: 2023/04/05 18:53:22 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exit(t_prog *pg, int c)
{
	if (c == 1)
		ft_putstr_fd("Error\n", 2);
	if (pg)
	{
		if (pg->a.array)
			free(pg->a.array);
		if (pg->b.array)
			free(pg->b.array);
		if (pg->sorted)
			free(pg->sorted);
        free(pg);
	}
	exit(c);
}

void	sort_tab(t_prog *pg)
{
	pg->sorted = ft_tabdup(pg->a.array, pg->a.size);
	ft_sort_int_tab(pg->sorted, pg->a.size);
}

void	ft_print_stacks(t_prog pg)
{
	printf("\nA stack\n");
	for (int i = 0; i < pg.a.size; i++)
		printf("%d\n", pg.a.array[i]);
	printf("\nB stack\n");
	for (int i = 0; i < pg.b.size; i++)
		printf("%d\n", pg.b.array[i]);
	// printf("\nsorted stack\n");
	// for (int i = 0; i < pg.a.size; i++)
	// 	printf("%d\n", pg.sorted[i]);
	printf("\n");
}
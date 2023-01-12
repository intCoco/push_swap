/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:20:16 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/24 21:21:20 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(int **tab, int ac)
{
	int tmp;

	tmp = tab[0][ac];
	while (ac > height(tab[0], ac) + 1)
	{
		tab[0][ac] = tab[0][ac + 1];
		ac--;
	}
	tab[ac] = tmp;
	write(1, "rra\n", 4);
}

void	ft_rrb(int **tab, int ac)
{
	int tmp;

	tmp = tab[1][ac];
	while (ac > height(tab[1], ac) + 1)
	{
		tab[1][ac] = tab[1][ac + 1];
		ac--;
	}
	tab[ac] = tmp;
	write(1, "rrb\n", 4);
}

void	ft_rrr(int **tab, int ac)
{
	int tmp;

	tmp = tab[0][ac];
	while (ac > height(tab[0], ac) + 1)
	{
		tab[0][ac] = tab[0][ac + 1];
		ac--;
	}
	tab[ac] = tmp;
	tmp = tab[1][ac];
	while (ac > height(tab[1], ac) + 1)
	{
		tab[1][ac] = tab[1][ac + 1];
		ac--;
	}
	tab[ac] = tmp;
	write(1, "rrr\n", 4);
}
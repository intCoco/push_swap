/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:18:42 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/24 21:20:08 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(int **tab, int ac)
{
	int tmp;
	int i;

	i = height(tab[0], ac);
	tmp = tab[0][i];
	while (i < ac - 1)
	{
		tab[0][i] = tab[0][i + 1];
		i++;
	}
	tab[i] = tmp;
	write(1, "ra\n", 3);
}

void	ft_rb(int **tab, int ac)
{
	int tmp;
	int i;

	i = height(tab[1], ac);
	tmp = tab[1][i];
	while (i < ac - 1)
	{
		tab[1][i] = tab[1][i + 1];
		i++;
	}
	tab[i] = tmp;
	write(1, "rb\n", 3);
}

void	ft_rr(int **tab, int ac)
{
	int tmp;
	int i;

	i = height(tab[0], ac);
	tmp = tab[0][i];
	while (i < ac)
	{
		tab[0][i] = tab[0][i + 1];
		i++;
	}
	tab[i] = tmp;
	i = height(tab[1], ac);
	tmp = tab[1][i];
	while (i < ac)
	{
		tab[1][i] = tab[1][i + 1];
		i++;
	}
	tab[i] = tmp;
}
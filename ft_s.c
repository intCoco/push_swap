/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:18:07 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/24 21:19:27 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(int **tab, int ac)
{
	int tmp;
	int i;

	i = height(tab[0], ac);
	tmp = tab[0][i];
	tab[0][i] = tab[0][i + 1];
	tab[0][i + 1] = tmp;
	write(1, "sa\n", 3);
}

void	ft_sb(int **tab, int ac)
{
	int tmp;
	int i;

	i = height(tab[1], ac);
	tmp = tab[1][i];
	tab[1][i] = tab[1][i + 1];
	tab[1][i + 1] = tmp;
	write(1, "sb\n", 3);
}

void	ft_ss(int **tab, int ac)
{
	int tmp;
	int i;

	i = height(tab[0], ac);
	tmp = tab[0][i];
	tab[0][i] = tab[0][i + 1];
	tab[0][1] = tmp;
	i = height(tab[1], ac);
	tmp = tab[1][i];
	tab[1][i] = tab[1][i + 1];
	tab[1][i + 1] = tmp;
	write(1, "ss\n", 3);
}
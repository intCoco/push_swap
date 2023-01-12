/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:22:42 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/24 21:58:48 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	height(int *tab, int ac)
{
	int	i;

	i = 0;
	while (i < ac && tab[i] == -1)
		i++;
	return (i);
}

void	ft_pa(int **tab, int ac)
{
	tab[1][height(tab[1], ac)] = tab[0][height(tab[0], ac)];
	tab[0][height(tab[0], ac)] = -1;
	write(1, "pa\n", 3);
}

void	ft_pb(int **tab, int ac)
{
	tab[0][height(tab[0], ac)] = tab[1][height(tab[1], ac)];
	tab[1][height(tab[1], ac)] = -1;
	write(1, "pb\n", 3);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:56:59 by chuchard          #+#    #+#             */
/*   Updated: 2023/04/05 18:20:38 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_char_check(int ac, char **av)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ac - 1)
	{
		j = -1;
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]) && !(j == 0 && (av[i][j] == '-'
						|| av[i][j] == '+')))
				ft_exit(0, 1);
	}
}

void	ft_issorted(t_prog *pg)
{
	int	i;

	i = -1;
	while (++i < pg->a.size - 1)
		if (pg->a.array[i] > pg->a.array[i + 1])
			return ;
	ft_exit(pg, 0);
}

void	ft_double_check(t_prog *pg)
{
	int	i;
	int	j;

	i = -1;
	while (++i < pg->a.size)
	{
		j = i;
		while (++j < pg->a.size)
			if (pg->a.array[i] == pg->a.array[j])
				ft_exit(pg, 1);
	}
}
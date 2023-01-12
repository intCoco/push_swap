/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:33:41 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/24 21:40:56 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert(int ac, char **av)
{
	int	**tab;
	int	i;

	i = 0;
	tab = (char **)malloc(sizeof(int *) * 2);
	tab[0] = malloc(sizeof(int) * ac);
	tab[1] = malloc(sizeof(int) * ac);
	while (i < ac)
	{
		tab[0][i] = ft_atoi(av[i]);
		tab[1][i] = -1;
		i++;
	}
	return (tab);
}

int	main(int ac, char **av)
{
	int	**tab;

	tab = convert(ac, av);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:33:41 by chuchard          #+#    #+#             */
/*   Updated: 2023/02/14 20:21:35 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	convert(t_prog prog, int ac, char **av)
{
	int	i;

	i = -1;
	prog.a.array = malloc(sizeof(int) * ac);
	prog.b.array = malloc(sizeof(int) * ac);
	while (++i < ac)
	{
		prog.a.array[i] = ft_atoi(av[i]);
		prog.a.size++;
	}
}

static int	check(int ac, char **av)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < ac)
	{
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]))
				return (0);
	}
	return (1);
}

static int	ft_issorted(t_prog prog)
{
	int	i;
	
	i = -1;
	while (++i < prog.a.size)
		if (prog.a.array[i] > prog.a.array[i + 1])
			return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_prog	prog;

	if (check(ac, av) == 1)
		perror("error");
	convert(prog, ac, av);
	if (ft_issorted(prog) == 1)
		return (0);
	if (prog.a.size <= 5)
		sort_small_stack(prog);
	else
		sort_big_stack();
}

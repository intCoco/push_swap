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

void	ft_exit(t_prog prog, char *str)
{
	ft_printf("Error\n%s\n", str);
	if (prog->a.array)
		free(prog->a.array);
	if (prog->b.array)
		free(prog->b.array);
	exit(1);
}

void	convert(t_prog prog, int ac, char **av)
{
	int	i;

	i = -1;
	prog->a.array = malloc(sizeof(int) * ac);
	prog->b.array = malloc(sizeof(int) * ac);
	if (!prog->a.array || !prog->b.array)
		ft_exit(prog, "Malloc Error");
	while (++i < ac)
	{
		prog->a.array[i] = ft_atoi(av[i]);
		prog->a.size++;
	}
}

void	check(int ac, char **av)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < ac)
	{
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]))
				ft_exit(0, "Invalid input");
	}
}

int	ft_issorted(t_prog prog)
{
	int	i;
	
	i = -1;
	while (++i < prog.a.size)
		if (prog.a.array[i] > prog.a.array[i + 1])
			return ;
	ft_exit(prog, "Stack is already sorted")
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:33:41 by chuchard          #+#    #+#             */
/*   Updated: 2023/03/07 16:05:02 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	ft_exit(t_prog *prog, int c)
{
	if (c == 1)
		ft_putstr_fd("Error\n", 2);
	if (prog)
	{
		if (prog->a.array)
			free(prog->a.array);
		if (prog->b.array)
			free(prog->b.array);
	}
	system("leaks push_swap");
	exit(c);
}

int	ft_psw_atoi(t_prog *prog, char *str)
{
	int		i;
	int		sign;
	long	nbint;

	i = 0;
	sign = 1;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			sign *= -1;
		i++;
	}
	nbint = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nbint = nbint * 10 + str[i] - '0';
		i++;
		if (sign > 0 && nbint > INT_MAX)
			ft_exit(prog, 1);
		else if (sign < 0 && -nbint < INT_MIN)
			ft_exit(prog, 1);
	}
	return (nbint * sign);
}

void	convert(t_prog *prog, int ac, char **av)
{
	int	i;

	i = -1;
	prog->a.array = malloc(sizeof(int) * (ac + 1));
	prog->b.array = malloc(sizeof(int) * (ac + 1));
	if (!prog->a.array || !prog->b.array)
		ft_exit(prog, 1);
	while (++i < ac)
	{
		prog->a.array[i] = ft_psw_atoi(prog, av[i]);
		prog->a.size++;
	}
}

void	ft_char_check(int ac, char **av)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]) && !(j == 0 && (av[i][j] == '-'
				|| av[i][j] == '+')))
					ft_exit(0, 1);
		}
	}
}

void	ft_issorted(t_prog *prog)
{
	int	i;

	i = -1;
	while (++i < prog->a.size - 1)
		if (prog->a.array[i] > prog->a.array[i + 1])
			return ;
	ft_exit(prog, 0);
}

void	ft_double_check(t_prog *prog)
{
	int	i;
	int	j;

	i = -1;
	while (++i < prog->a.size)
	{
		j = i;
		while (++j < prog->a.size)
			if (prog->a.array[i] == prog->a.array[j])
				ft_exit(prog, 1);
	}
}

void	ft_sort_small_stack()
{
	
}

int	main(int ac, char **av)
{
	t_prog	*prog;
	char	**av2;

	prog = ft_calloc(1, sizeof(t_prog));
	if (ac < 2)
		ft_exit(0, 0);
	if (ac == 2)
	{
		av2 = ft_split(av[1], ' ');
		ac = ft_splitcount(av[1], ' ');
	}
	else
	{
		av2 = &av[1];
		ac--;
	}
	ft_char_check(ac, av2);
	convert(prog, ac, av2);
	ft_double_check(prog);
	ft_issorted(prog);
	ft_sort_small_stack(prog);
	ft_exit(prog, 0);
}

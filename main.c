/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:33:41 by chuchard          #+#    #+#             */
/*   Updated: 2023/03/08 15:26:09 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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
	}
	system("leaks push_swap");
	exit(c);
}

int	ft_psw_atoi(t_prog *pg, char *str)
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
			ft_exit(pg, 1);
		else if (sign < 0 && -nbint < INT_MIN)
			ft_exit(pg, 1);
	}
	return (nbint * sign);
}

void	convert(t_prog *pg, int ac, char **av)
{
	int	i;

	i = -1;
	pg->a.array = malloc(sizeof(int) * (ac + 1));
	pg->b.array = malloc(sizeof(int) * (ac + 1));
	if (!pg->a.array || !pg->b.array)
		ft_exit(pg, 1);
	while (++i < ac)
	{
		pg->a.array[i] = ft_psw_atoi(pg, av[i]);
		pg->a.size++;
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

void	ft_sort_up_to_3(t_prog *pg)
{
	if (pg->a.array[1] < pg->a.array[0] && pg->a.array[0] < pg->a.array[2])
		ft_sa(&pg);
	if (pg->a.array[2] < pg->a.array[1] && pg->a.array[1] < pg->a.array[0])
	{
		ft_sa(&pg);
		ft_rra(&pg);
	}
	if (pg->a.array[1] < pg->a.array[2] && pg->a.array[2] < pg->a.array[0])
		ft_ra(&pg);
	if (pg->a.array[0] < pg->a.array[2] && pg->a.array[2] < pg->a.array[1])
	{
		ft_sa(&pg);
		ft_ra(&pg);
	}
	if (pg->a.array[2] < pg->a.array[0] && pg->a.array[0] < pg->a.array[1])
		ft_rra(&pg);
}

int	ft_find_min_idx(t_stack stack)
{
	int	i;
	int	idx;
	int	min;

	i = -1;
	idx = 0;
	while (++i < stack.size)
		if (min > stack.array[i])
		{
			min = stack.array[i];
			min = i;
		}
	return (idx);
}

void	ft_remonteetpush(t_stack *stack, char c)
{
	int	i;

	i = ft_find_min_idx(*stack);
	while (i <= (stack->size - 1) / 2 && i-- > 0)
		ft_rev_rot(stack, c);
	while (i > (stack->size - 1) / 2 && i++ <= stack->size - 1)
		ft_rot(stack, c);
	if (c == A)
		ft_push(stack, B);
	else
		ft_push(stack, A);
}

void	ft_sort_4_to_5(t_prog *pg)
{
	if (pg->a.size == 5)
		ft_remonteetpush(&pg->a, A);
	ft_remonteetpush(&pg->a, A);
	ft_sort_up_to_3(pg);
	if (pg->a.size == 5)
		ft_push(&pg->a, A);
	ft_push(&pg->a, A);
}


int	main(int ac, char **av)
{
	t_prog	*pg;
	char	**av2;

	pg = ft_calloc(1, sizeof(t_prog));
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
	convert(pg, ac, av2);
	pg->a.other = &pg->b;
	ft_double_check(pg);
	ft_issorted(pg);
	ft_sort_small_stack(pg);
	ft_exit(pg, 0);
}

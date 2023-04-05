/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:52:13 by chuchard          #+#    #+#             */
/*   Updated: 2023/04/05 18:52:58 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if (str[i] == '\0')
		ft_exit(pg, 1);
	nbint = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nbint = nbint * 10 + str[i] - '0';
		i++;
		if (sign > 0 && nbint > INT_MAX)
			ft_exit(pg, 1);
		else if (sign < 0 && -(nbint) < INT_MIN)
			ft_exit(pg, 1);
	}
	return (nbint * sign);
}

void	convert(t_prog *pg, int ac, char **av)
{
	int	i;

	i = -1;
	pg->a.array = malloc(sizeof(int) * (ac - 1));
	pg->b.array = malloc(sizeof(int) * (ac - 1));
	if (!pg->a.array || !pg->b.array)
		ft_exit(pg, 1);
	while (++i < ac - 1)
	{
		pg->a.array[i] = ft_psw_atoi(pg, av[i]);
		pg->a.size++;
	}
}
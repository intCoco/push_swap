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

static int	ft_conv_in_int(const char *str, int i)
{
	int	nbint;

	nbint = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nbint = nbint * 10 + ((char *)str)[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		
	return (nbint);
}

int	ft_ps_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nbint;

	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	nbint = ft_conv_in_int(str, i);
	nbint *= sign;
	return (nbint);
}

int	*convert(int ac, char **av)
{
	t_stack	stack[2];
	int	i;

	i = -1;
	stack[0]->array = malloc(sizeof(int) * ac);
	stack[1]->array = malloc(sizeof(int) * ac);
	while (++i < ac)
	{
		stack[0]->array[i] = ft_atoi(av[i]);
	}
	return (tab);
}

int	main(int ac, char **av)
{
	int	**tab;

	tab = convert(ac, av);
}

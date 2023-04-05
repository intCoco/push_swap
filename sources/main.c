/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:33:41 by chuchard          #+#    #+#             */
/*   Updated: 2023/04/05 18:53:43 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_up_to_500(t_prog *pg)
{
	int	chunk;
	int	i;

	chunk = 1;
	while (pg->a.size > 0)
	{
		i = find_closest_min(*pg, pg->a, chunk);
		if (i == -1 && chunk < pg->chunk_nb)
			chunk += 1;
		else
			ft_top_and_push(&pg->a, i, A);
	}
	while (pg->b.size > 0)
		ft_top_and_push(&pg->b, ft_find_max_idx(pg->b), B);
}

void	ft_initialize(t_prog *pg)
{
	pg->size = pg->a.size;
	pg->chunk_nb = 11 * (pg->size > 100) + 5 * (pg->size <= 100);
	pg->a.other = &pg->b;
	pg->b.other = &pg->a;
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
		ac = ft_splitcount(av[1], ' ') + 1;
	}
	else
		av2 = &av[1];
	ft_initialize(pg);
	ft_char_check(ac, av2);
	convert(pg, ac, av2);
	ft_double_check(pg);
	ft_issorted(pg);
	sort_tab(pg);
	if (pg->size == 2)
		ft_swap(&pg->a, A);
	else if (pg->size <= 500)
		ft_sort_up_to_500(pg);
	ft_print_stacks(*pg);
	ft_exit(pg, 0);
}

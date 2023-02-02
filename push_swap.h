/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:36:11 by chuchard          #+#    #+#             */
/*   Updated: 2023/02/02 20:24:10 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_link
{
	int 			value;
	struct s_link	*next;
}	t_link;

int		height(int *tab, int ac);
void	ft_sa(int **tab, int ac);
void	ft_sb(int **tab, int ac);
void	ft_ss(int **tab, int ac);
void	ft_rb(int **tab, int ac);
void	ft_ra(int **tab, int ac);
void	ft_rr(int **tab, int ac);
void	ft_rra(int **tab, int ac);
void	ft_rrb(int **tab, int ac);
void	ft_rrr(int **tab, int ac);
void	ft_pa(int **tab, int ac);
void	ft_pb(int **tab, int ac);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push_swap.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:41:43 by lhageman       #+#    #+#                */
/*   Updated: 2019/10/23 19:15:22 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_checker.h"
# include "libft/libft.h"
# include "libft/ft_printf.h"

int     ft_sort(t_arrlist *list);
int		ft_bubblesort(t_arrlist *list_og);
int     ft_sa(t_arrlist *list);
int     ft_sb(t_arrlist *list);
int     ft_ss(t_arrlist *list);
int     ft_pa(t_arrlist *list);
int     ft_pb(t_arrlist *list);
int     ft_ra(t_arrlist *list);
int     ft_rra(t_arrlist *list);
void	ft_sorter(t_arrlist *list, int middle);

#endif

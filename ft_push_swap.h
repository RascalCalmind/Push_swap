/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push_swap.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:41:43 by lhageman       #+#    #+#                */
/*   Updated: 2019/11/30 16:40:49 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_checker.h"
# include "libft/libft.h"
# include "libft/ft_printf.h"

int		ft_sort(t_arrlist *list);
int		ft_bubblesort(t_arrlist *list_og);
int		ft_sa(t_arrlist *list);
int		ft_sb(t_arrlist *list);
int		ft_ss(t_arrlist *list);
int		ft_pa(t_arrlist *list);
int		ft_pb(t_arrlist *list);
int		ft_ra(t_arrlist *list);
int		ft_rb(t_arrlist *list);
int     ft_rr(t_arrlist *list);
int		ft_rra(t_arrlist *list);
int		ft_rrb(t_arrlist *list);
int     ft_rrr(t_arrlist *list);
void	ft_sorter(t_arrlist *list, int middle);
int	    ft_sorted(t_arrlist *list);
int		ft_sort_bigger(t_arrlist *list, int middle);
void	ft_sort_three(t_arrlist *list);
int     ft_sort_back(t_arrlist *list);
void	ft_print_stacks_compare(t_arrlist *start, t_arrlist *finish);
int		ft_a_sorted(t_arrlist *list);
void	ft_print_char_array(char **arr);
void    ft_print_int_array(int *arr);
int		ft_check_file(char *file);
void	ft_list_copy(t_arrlist *list, t_arrlist *copy);
void	ft_find_bignum(t_arrlist *list);

#endif

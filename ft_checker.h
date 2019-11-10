/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_checker.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:41:38 by lhageman       #+#    #+#                */
/*   Updated: 2019/11/04 14:58:35 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct		s_arrlist
{
	int		*arr_a;
	int		*arr_b;
	short	vflag;
	short	len_a;
	short	len_b;
	short	prog;
}					t_arrlist;

int					ft_valid_input(char *str);
int					ft_check_input(char **argv);
int					ft_store_input(char **argv, t_arrlist *arlst);
void				ft_print_int_array(int *array, int len);
void				ft_print_stacks(t_arrlist *list);
void				ft_set_int_array_list(t_arrlist *list, int len);
int					ft_read_input(t_arrlist *list);
int					ft_swap(char *str, t_arrlist *list);
int					ft_push(char *str, t_arrlist *list);
int					ft_rotate(char *str, t_arrlist *list);
int					ft_reverse_rotate(char *str, t_arrlist *list);
int					ft_sa(t_arrlist *list);
int					ft_sb(t_arrlist *list);
void				ft_switch_down(int i, int len, int *arr);
void				ft_switch_up(int *arr, int len);
void				ft_check_stack(t_arrlist *list);
void				ft_free_arrlist(t_arrlist *list);

#endif

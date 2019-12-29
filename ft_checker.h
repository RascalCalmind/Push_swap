/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_checker.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:41:38 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/29 18:44:38 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef	struct		s_buffer
{
	char	buf[1024];
	char	*str;
	int		len;
	int		count;
	int		fd;
}					t_buffer;

typedef struct		s_arrlist
{
	int				*arr_a;
	int				*arr_b;
	short			vflag;
	short			fflag;
	short			len_a;
	short			len_b;
	short			prog;
	short			total_len;
	t_buffer		*buf;
}					t_arrlist;

typedef struct		s_fflag_list
{
	int		fd;
	int		ret;
	char	**arr;
}					t_fflag_list;

int					ft_valid_input(char *str);
int					ft_check_input(char **argv);
int					ft_store_input(char **argv, t_arrlist *arlst);
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
int					ft_free_arrlist(t_arrlist *list);
int					ft_open_file(char *file, char *numbers, char **arr,
					t_fflag_list *flist);
void				ft_set_flist(t_fflag_list *list);
int					ft_free_flist(t_fflag_list *list);

void				ft_printbuffer(t_buffer *buf);
void				ft_buffer_add(t_buffer *buf, char *str);
void				ft_stacks_to_buf(t_arrlist *list);
void				ft_buffer_add_stack(t_buffer *buf, char *str);
int					ft_len_stack(int len_a, int len_b);
void				ft_string_to_buffer(t_buffer *buf, char *str, size_t len);

int					ft_find_doubles(t_arrlist *list);
int					ft_store_int(char *str);
int					ft_store_file(char **argv, t_arrlist *arlst, int len);

#endif

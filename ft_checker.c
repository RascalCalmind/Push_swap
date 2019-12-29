/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_checker.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:41:33 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/29 17:28:54 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include <stdio.h>

int		ft_free_quick(t_arrlist *list)
{
	ft_free_arrlist(list);
	ft_dprintf(2, "Error\n");
	return (-1);
}

int		main(int argc, char **argv)
{
	int			ret;
	t_arrlist	*arlst;

	if (argc > 1)
	{
		ret = ft_check_input(argv);
		if (ret == -1)
			return (-1);
		arlst = malloc(sizeof(t_arrlist));
		if (!arlst)
			return (-1);
		ret = ft_store_input(argv, arlst);
		if (ret == -1)
			return (ft_free_quick(arlst));
		if (arlst->fflag == 1 || (arlst->vflag == 0 && arlst->fflag == 0))
			ft_print_stacks(arlst);
		if (arlst->buf)
			ft_printbuffer(arlst->buf);
		ret = ft_read_input(arlst);
		if (ret == -1)
			return (ft_free_quick(arlst));
		ft_check_stack(arlst);
		ft_free_arrlist(arlst);
	}
	return (0);
}

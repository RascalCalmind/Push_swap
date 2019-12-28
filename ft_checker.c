/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_checker.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:41:33 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/28 16:42:03 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include <stdio.h>

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
		if (ft_store_input(argv, arlst) == -1)
			return (-1);
		if (arlst->fflag == 1 || (arlst->vflag == 0 && arlst->fflag == 0))
			ft_print_stacks(arlst);
		ret = ft_read_input(arlst);
		if (ret == -1)
		{
			ft_free_arrlist(arlst);
			ft_dprintf(2, "Error\n");
			return (-1);
		}
		ft_check_stack(arlst);
		ft_free_arrlist(arlst);
		arlst = NULL;
	}
	return (0);
}

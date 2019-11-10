/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push_swap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:41:41 by lhageman       #+#    #+#                */
/*   Updated: 2019/11/04 14:59:55 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_push_swap.h"
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
		ret = ft_store_input(argv, arlst);
		arlst->prog = 1;
		if (ret == -1)
		{
			ft_free_arrlist(arlst);
			return (-1);
		}
		ret = ft_sort(arlst);
		if (ret == -1)
		{
			ft_free_arrlist(arlst);
			return (-1);
		}
		ft_free_arrlist(arlst);
	}
	return (0);
}

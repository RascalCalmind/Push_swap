/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_checker.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:41:33 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/26 18:16:19 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	if (argc > 1)
		printf("%s", argv[1]);
	return (0);
}

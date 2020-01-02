/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_input.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/27 18:54:58 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/02 20:10:51 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int		ft_check_swap(char *str, int i)
{
	if (str[0] == 's')
	{
		if ((str[1] == 'a' || str[1] == 'b' || str[1] == 's') && i == 2)
			return (0);
	}
	if (str[0] == 'p')
	{
		if ((str[1] == 'a' || str[1] == 'b') && i == 2)
			return (0);
	}
	if (str[0] == 'r')
	{
		if ((str[1] == 'a' || str[1] == 'b') && i == 2)
			return (0);
		if (str[1] == 'r')
		{
			if (i == 2)
				return (0);
			if ((str[2] == 'a' || str[2] == 'b' || str[2] == 'r') && i == 3)
				return (0);
		}
	}
	return (-1);
}

int		ft_strcheck(char *str, t_arrlist *list, int i, int ret)
{
	if (str[0] == '\0')
	{
		free(str);
		return (0);
	}
	ret = ft_check_swap(str, i);
	if (ret == -1)
	{
		free(str);
		return (-1);
	}
	i = ft_swap(str, list);
	if (i != 0)
		return (i);
	ft_strclr(str);
	return (1);
}

int		ft_read_loop(t_read_check *rc, t_arrlist *list)
{
	int ret;

	ret = 0;
	ret = ft_strcheck(rc->str, list, rc->i, ret);
	if (ret == -1)
		return (-1);
	if (ret == 0)
		return (0);
	if (list->buf)
		ft_printbuffer(list->buf);
	if (list->buf)
		ft_printbuffer(list->buf);
	rc->i = 0;
	return (1);
}

void	ft_create_rc(t_read_check *rc)
{
	if (!rc)
		return ;
	rc->ch = '\0';
	rc->str = ft_strnew(3);
	rc->i = 0;
	rc->ret = 0;
}

int		ft_read_input(t_arrlist *list)
{
	t_read_check *rc;

	rc = malloc(sizeof(t_read_check));
	ft_create_rc(rc);
	if (!rc)
		return (-1);
	while (read(STDIN_FILENO, &rc->ch, 1) > 0)
	{
		if (rc->ch != '\n')
		{
			if (rc->i > 2 || rc->i == -1)
				return (ft_free_check(rc, -1));
			rc->str[rc->i] = rc->ch;
			rc->i++;
		}
		if (rc->ch == '\n')
		{
			rc->ret = ft_read_loop(rc, list);
			if (rc->ret == -1)
				return (ft_free_check(rc, -1));
			if (rc->ret == 0)
				return (ft_free_check(rc, 0));
		}
	}
	return (ft_free_check(rc, 0));
}

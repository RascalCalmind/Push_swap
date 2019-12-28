/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_buffer.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/16 14:20:54 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/28 14:11:49 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	ft_buffer_to_string(t_buffer *buf)
{
	int i;

	i = 0;
	while (i < buf->len)
	{
		buf->str[i + buf->count] = buf->buf[i];
		i++;
	}
}

void	ft_printbuffer(t_buffer *buf)
{
	if (buf->str == NULL)
		write(1, &buf->buf, buf->len);
	else
		ft_buffer_to_string(buf);
	buf->len = 0;
}

void	ft_put_to_buffer(t_buffer *buf, char c)
{
	buf->buf[buf->len] = c;
	buf->len++;
	if (buf->len == 1024)
		ft_printbuffer(buf);
}

void	ft_string_to_buffer(t_buffer *buf, char *str, size_t len)
{
	while (len > 0)
	{
		ft_put_to_buffer(buf, *str);
		str++;
		len--;
	}
	buf->str = NULL;
}

void	ft_buffer_add(t_buffer *buf, char *str)
{
	ft_string_to_buffer(buf, str, ft_strlen(str));
	if (ft_strlen(str) <= 4)
		buf->count += 1;
}

void	ft_buffer_add_stack(t_buffer *buf, char *str)
{
	ft_string_to_buffer(buf, str, ft_strlen(str));
}

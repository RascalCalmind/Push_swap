/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/24 22:17:20 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/21 14:44:11 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(const char *str);
void	ft_putnbr(long long nb);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
char	*strsub(char const *s, unsigned int start, size_t len);
char	*ft_strnew(size_t len);
char	*ft_strnjoin(const char *s1, const char *s2, int len1, int len2);

size_t	ft_strlen(const char *s);

int		ft_isspace(char c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

#endif

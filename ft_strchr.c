/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:38:31 by tkanzaki          #+#    #+#             */
/*   Updated: 2020/11/29 15:38:32 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strchr_n(const char *s, char c)
{
	int				i;
	unsigned char	*p;

	p = (unsigned char*)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (p[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen(const char *str)
{
	int cnt;

	cnt = 0;
	while (str[cnt] != '\0')
		cnt++;
	return (cnt);
}

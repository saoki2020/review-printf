/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:33:13 by tkanzaki          #+#    #+#             */
/*   Updated: 2020/11/29 15:33:40 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
	return (1);
}

void	ft_putchar_fd_n(char c, int fd, int num)
{
	while (num--)
		ft_putchar_fd(c, fd);
}

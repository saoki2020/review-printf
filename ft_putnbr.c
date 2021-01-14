/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:37:08 by tkanzaki          #+#    #+#             */
/*   Updated: 2020/11/29 15:37:26 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_digit(unsigned long long n, int fd,
char *base, unsigned int size)
{
	char	c;

	if (n >= size)
	{
		ft_print_digit(n / size, fd, base, size);
	}
	c = base[n % size];
	write(fd, &c, sizeof(char));
}

void		ft_putnbr_u_fd(unsigned long long n, int fd, t_data_flag data)
{
	if (data.specifier == SPEC_SX || data.specifier == SPEC_P)
		ft_print_digit(n, fd, "0123456789abcdef", 16);
	else if (data.specifier == SPEC_LX)
		ft_print_digit(n, fd, "0123456789ABCDEF", 16);
	else
		ft_print_digit(n, fd, "0123456789", 10);
}

void		ft_put_plus_minus(long long n)
{
	if (n < 0)
		write(1, "-", 1);
}

int			ft_get_ndigit(long long n)
{
	int					i;
	unsigned long long	n_u;

	i = 0;
	if (n < 0)
		n_u = -n;
	else
		n_u = n;
	while (n_u > 0)
	{
		i++;
		n_u /= 10;
	}
	return (i);
}

int			ft_get_ndigit_u(unsigned long long n_u, t_data_flag data)
{
	int i;

	i = 0;
	while (n_u > 0)
	{
		i++;
		if (data.specifier == SPEC_U)
			n_u /= 10;
		else
			n_u /= 16;
	}
	return (i);
}

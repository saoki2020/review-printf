/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:31:24 by tkanzaki          #+#    #+#             */
/*   Updated: 2020/11/29 15:31:27 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_null_print(t_data_flag *data, char **s)
{
	*s = "(null)";
	data->putlen = 6;
	if (data->putlen > data->acc)
		data->putlen = data->acc;
	return (0);
}

int		ft_char_count(int c)
{
	int	n;

	if (c <= 0x7F)
		n = 1;
	else if (c <= 0x7FF)
		n = 2;
	else if (c <= 0xFFFF)
		n = 3;
	else
		n = 4;
	return (n);
}

int		ft_set_string(va_list *ap, t_data_flag *data, char **s)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	if (ap == NULL)
		return (ft_null_print(data, s));
	if ((*s = (char *)va_arg(*ap, char *)) == NULL)
		return (ft_null_print(data, s));
	while ((data->putlen += n) < data->acc && (*s)[i])
	{
		n = ft_char_count((*s)[i++]);
	}
	return (n);
}

void	ft_print_string(va_list *ap, t_data_flag *data)
{
	char	*s;
	int		n;

	if (data->acc < 0)
		data->acc = INT_MAX;
	n = ft_set_string(ap, data, &s);
	if (data->putlen > data->acc)
		data->putlen -= n;
	data->field = (data->field <= data->putlen
	? 0 : data->field - data->putlen);
	if (!data->flag[FLAG_MINUS])
		ft_putchar_fd_n((data->flag[FLAG_ZERO]
		? CHARA_ZERO : CHARA_FIELD), 1, data->field);
	n = data->putlen;
	while (n > 0)
		n -= ft_putchar_fd(*s++, 1);
	if (data->flag[FLAG_MINUS])
		ft_putchar_fd_n(CHARA_FIELD, 1, data->field);
}

void	ft_print_char(va_list *ap, t_data_flag *data)
{
	char	c;

	c = (char)va_arg(*ap, int);
	data->putlen = ft_char_count(c);
	data->field = (data->field <= data->putlen
	? 0 : data->field - data->putlen);
	if (!data->flag[FLAG_MINUS])
		ft_putchar_fd_n(CHARA_FIELD, 1, data->field);
	ft_putchar_fd(c, 1);
	if (data->flag[FLAG_MINUS])
		ft_putchar_fd_n(CHARA_FIELD, 1, data->field);
}

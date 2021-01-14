/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:13:04 by tkanzaki          #+#    #+#             */
/*   Updated: 2020/11/29 15:13:10 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_non_specifier(const char **start, const char **fmt,
t_data_flag *data)
{
	if (!**fmt)
		return (-1);
	data->putlen = *fmt - *start;
	write(1, *start, data->putlen);
	return (data->putnum + data->putlen);
}

void	ft_print_percent(t_data_flag *data)
{
	data->putlen = 1;
	data->field = (data->field <= data->putlen
	? 0 : data->field - data->putlen);
	if (!data->flag[FLAG_MINUS] && !data->flag[FLAG_ZERO])
		ft_putchar_fd_n(' ', 1, data->field);
	ft_putchar_fd_n('0', 1, (data->flag[FLAG_ZERO] && !data->flag[FLAG_MINUS]
	? data->field : 0));
	write(1, "%%", 1);
	if (data->flag[FLAG_MINUS])
		ft_putchar_fd_n(' ', 1, data->field);
}

int		ft_print_data_f(const char **start, const char **fmt,
va_list *ap, t_data_flag *data)
{
	if (data->specifier == -1)
		return (ft_non_specifier(start, fmt, data));
	(*fmt)++;
	if (data->specifier == SPEC_D || data->specifier == SPEC_I)
		ft_print_int(ap, data);
	else if (data->specifier >= SPEC_U && data->specifier <= SPEC_LX)
		ft_print_unsigned(ap, data);
	else if (data->specifier == SPEC_C)
		ft_print_char(ap, data);
	else if (data->specifier == SPEC_S)
		ft_print_string(ap, data);
	else if (data->specifier == SPEC_P)
		ft_print_pointer(ap, data);
	else
		ft_print_percent(data);
	return (data->putnum + data->putlen + data->field);
}

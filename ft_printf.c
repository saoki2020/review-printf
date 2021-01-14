/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:18:59 by tkanzaki          #+#    #+#             */
/*   Updated: 2020/11/29 15:32:47 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_field_acc(const char **fmt, va_list *ap,
int mode, t_data_flag *data)
{
	int num;

	num = -1;
	if (**fmt == '*')
	{
		num = va_arg(*ap, int);
		if (num < 0 && mode == FIELD)
		{
			num *= -1;
			data->flag[FLAG_MINUS] = 1;
		}
		else if (num < -1)
			num = -1;
		(*fmt)++;
	}
	else if (mode == ACC || ft_isdigit(**fmt))
	{
		num = 0;
		while (ft_isdigit(**fmt))
			num = num * 10 + (*((*fmt)++) - '0');
	}
	return (num);
}

void	ft_init_data_f(t_data_flag *data, int n)
{
	data->flag[FLAG_SHARP] = 0;
	data->flag[FLAG_ZERO] = 0;
	data->flag[FLAG_MINUS] = 0;
	data->flag[FLAG_SPACE] = 0;
	data->flag[FLAG_PLUS] = 0;
	data->field = 0;
	data->acc = -1;
	data->modifier = -1;
	data->specifier = -1;
	data->putnum = (n < 0 ? 0 : n);
	data->putlen = 0;
}

void	ft_print_str_f(const char **start, const char **fmt,
int *n, va_list *ap)
{
	int			num;
	t_data_flag data;

	(*fmt)++;
	ft_init_data_f(&data, *n);
	while ((num = ft_strchr_n(FLAGS, **fmt)) >= 0)
	{
		data.flag[num] = 1;
		(*fmt)++;
	}
	data.field = ft_get_field_acc(fmt, ap, FIELD, &data);
	if (**fmt == '.')
	{
		(*fmt)++;
		data.acc = ft_get_field_acc(fmt, ap, ACC, &data);
	}
	data.specifier = ft_strchr_n(SPECIFIERS, **fmt);
	num = ft_print_data_f(start, fmt, ap, &data);
	*n = ((*n == 0 || num >= 0) ? num : *n);
}

void	ft_print_str(const char **start, const char **fmt, int *n)
{
	while (**fmt != '%' && **fmt)
		(*fmt)++;
	write(1, *start, *fmt - *start);
	*n += *fmt - *start;
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			n;
	const char	*start;

	n = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
		n = -1;
	while (n >= 0 && *fmt)
	{
		start = fmt;
		if (*start != '%')
			ft_print_str(&start, &fmt, &n);
		else
			ft_print_str_f(&start, &fmt, &n, &ap);
	}
	va_end(ap);
	return (n);
}

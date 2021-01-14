/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:20:32 by tkanzaki          #+#    #+#             */
/*   Updated: 2020/11/29 15:20:36 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_putlen(t_data_flag *data, long long num_l,
unsigned long long num_ul)
{
	data->flag[FLAG_ZERO] = (data->flag[FLAG_ZERO] && (data->acc == -1));
	if (data->specifier == SPEC_D || data->specifier == SPEC_I)
	{
		data->putlen = ft_get_ndigit(num_l);
		data->acc = (data->acc <= data->putlen
		? (num_l == 0 && data->acc) : data->acc - data->putlen);
		data->putlen += data->acc + (num_l < 0);
		data->field = (data->field <= data->putlen
		? 0 : data->field - data->putlen);
	}
	else if (data->specifier >= SPEC_U && data->specifier <= SPEC_LX)
	{
		data->putlen = ft_get_ndigit_u(num_ul, *data);
		data->acc = (data->acc <= data->putlen
		? (num_ul == 0 && data->acc) : data->acc - data->putlen);
		data->putlen += data->acc
		+ ft_strlen(PREFIX_POINTER) * (num_ul != 0 && num_l != 0);
		data->field = (data->field <= data->putlen
		? 0 : data->field - data->putlen);
	}
}

void	ft_print_pointer(va_list *ap, t_data_flag *data)
{
	unsigned long num;

	data->specifier = SPEC_SX;
	if ((num = (unsigned long)va_arg(*ap, void *)) == 0)
	{
		data->acc = (data->acc == -1 ? 1 : data->acc);
		data->putlen = ft_strlen(PREFIX_POINTER) + data->acc;
		data->field = (data->field <= data->putlen
		? 0 : data->field - data->putlen);
	}
	else
		ft_get_putlen(data, 1, num);
	if (!data->flag[FLAG_MINUS] && !data->flag[FLAG_ZERO])
		ft_putchar_fd_n(CHARA_FIELD, 1, data->field);
	write(1, PREFIX_POINTER, ft_strlen(PREFIX_POINTER));
	ft_putchar_fd_n(CHARA_ZERO, 1, data->acc
	+ (data->flag[FLAG_ZERO] && !data->flag[FLAG_MINUS]
	? data->field : 0));
	if (num)
		ft_putnbr_u_fd(num, 1, *data);
	if (data->flag[FLAG_MINUS])
		ft_putchar_fd_n(CHARA_FIELD, 1, data->field);
}

void	ft_print_unsigned(va_list *ap, t_data_flag *data)
{
	unsigned int num;

	num = (unsigned int)va_arg(*ap, int);
	ft_get_putlen(data, 0, num);
	if (!data->flag[FLAG_MINUS] && !data->flag[FLAG_ZERO])
		ft_putchar_fd_n(CHARA_FIELD, 1, data->field);
	ft_putchar_fd_n(CHARA_ZERO, 1, data->acc
	+ (data->flag[FLAG_ZERO] && !data->flag[FLAG_MINUS]
	? data->field : 0));
	if (num)
		ft_putnbr_u_fd(num, 1, *data);
	if (data->flag[FLAG_MINUS])
		ft_putchar_fd_n(CHARA_FIELD, 1, data->field);
}

void	ft_print_int(va_list *ap, t_data_flag *data)
{
	long long num;

	num = (long long)va_arg(*ap, int);
	ft_get_putlen(data, num, 0);
	if (!data->flag[FLAG_MINUS] && !data->flag[FLAG_ZERO])
		ft_putchar_fd_n(CHARA_FIELD, 1, data->field);
	ft_put_plus_minus(num);
	ft_putchar_fd_n(CHARA_ZERO, 1, data->acc
	+ (data->flag[FLAG_ZERO] && !data->flag[FLAG_MINUS]
	? data->field : 0));
	if (num)
		ft_putnbr_u_fd(num * (num < 0 ? -1 : 1), 1, *data);
	if (data->flag[FLAG_MINUS])
		ft_putchar_fd_n(CHARA_FIELD, 1, data->field);
}

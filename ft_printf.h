/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkanzaki <tkanzaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:16:40 by tkanzaki          #+#    #+#             */
/*   Updated: 2020/11/29 15:03:52 by tkanzaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# define PREFIX_POINTER	"0x"
# define CHARA_FIELD    ' '
# define CHARA_ZERO     '0'
# define FLAGS          "#0- +"
# define SPECIFIERS     "diuxXcsp%"

typedef enum	e_mode
{
	FIELD = 0,
	ACC = 1
}				t_mode;

typedef enum	e_flag
{
	FLAG_SHARP = 0,
	FLAG_ZERO = 1,
	FLAG_MINUS = 2,
	FLAG_SPACE = 3,
	FLAG_PLUS = 4
}				t_flag;

typedef enum	e_spec
{
	SPEC_D = 0,
	SPEC_I = 1,
	SPEC_U = 2,
	SPEC_SX = 3,
	SPEC_LX = 4,
	SPEC_C = 5,
	SPEC_S = 6,
	SPEC_P = 7,
	SPEC_PER = 8
}				t_spec;

typedef struct	s_data_flag
{
	int			flag[5];
	int			field;
	int			acc;
	int			modifier;
	int			specifier;
	int			putnum;
	int			putlen;
	int			copy_acc;
}				t_data_flag;

int				ft_printf(const char *s, ...);
int				ft_isdigit(int n);
int				ft_print_data_f(const char **s1, const char **s2,
va_list *ap, t_data_flag *data);
int				ft_putchar_fd(char c, int n);
int				ft_strchr_n(const char *s, char c);
int				ft_strlen(const char *s);
int				ft_get_ndigit(long long ll);
int				ft_get_ndigit_u(unsigned long long ull, t_data_flag tdf);
void			ft_put_plus_minus(long long ll);
void			ft_print_int(va_list *ap, t_data_flag *data);
void			ft_print_unsigned(va_list *ap, t_data_flag *data);
void			ft_print_char(va_list *ap, t_data_flag *data);
void			ft_print_string(va_list *ap, t_data_flag *data);
void			ft_print_pointer(va_list *ap, t_data_flag *data);
void			ft_putnbr_u_fd(unsigned long long ull, int n, t_data_flag tdf);
void			ft_putchar_fd_n(char c, int fd, int n);

#endif

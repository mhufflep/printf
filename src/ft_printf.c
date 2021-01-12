/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 07:58:25 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/11 14:50:58 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_check.h"
#include "ft_printf.h"
#include "ft_is_type.h"
#include "ft_print_int.h"
#include "ft_print_flags.h"
#include "ft_print_chars.h"
#include "ft_set_defaults.h"
#include "ft_get_arguments.h"
#include "ft_get_parameters.h"
#include "ft_print_increment.h"
#include "ft_modify_parameters.h"

void	print_types(t_params *prm)
{
	print_char(prm);
	print_float(prm);
	print_string(prm);
	print_integer(prm);
	print_unsigned(prm);
	print_hexoctbin(prm);
	get_written_count(prm);
}

void	calculate_zero_spaces(t_params *prm)
{
	int	length;

	length = 0;
	length += check_flags(prm);
	length += check_char(prm);
	length += check_float(prm);
	length += check_string(prm);
	length += check_integer(prm);
	prm->spaces = get_positive(prm->width - length);
}

void	print_fragment(t_params *prm)
{
	calculate_zero_spaces(prm);
	if (prm->flags & F_LINE)
	{
		print_sign(prm);
		print_sharp(prm);
		print_precision(prm);
		print_types(prm);
		print_space(prm);
	}
	else
	{
		print_space(prm);
		print_sign(prm);
		print_zero(prm);
		print_sharp(prm);
		print_precision(prm);
		print_types(prm);
	}
}

int		get_params(const char *s, t_params *prm, va_list ap)
{
	int i;

	set_defaults(prm);
	i = 0;
	i += get_flags(&s[i], prm);
	i += get_width(&s[i], prm, ap);
	i += get_precision(&s[i], prm, ap);
	i += get_length(&s[i], prm);
	i += get_type(s[i], prm);
	i += 1;
	modify_params(prm);
	get_argument(prm, ap);
	return (i);
}

int		ft_printf(const char *s, ...)
{
	t_params	parameters;
	va_list		ptr;
	int			start;
	int			i;

	i = 0;
	start = 0;
	va_start(ptr, s);
	while (s && s[i] != '\0')
	{
		if (s[i] == '%')
		{
			ft_putstrn_inc(&s[start], i - start);
			i += get_params(&s[i + 1], &parameters, ptr);
			print_fragment(&parameters);
			start = i;
			continue;
		}
		i++;
	}
	va_end(ptr);
	if (s && s[start])
		ft_putstrn_inc(&s[start], i - start);
	return (symbol_counter(-1));
}

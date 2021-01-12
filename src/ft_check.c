/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 02:26:56 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/14 07:25:19 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_printf.h"
#include "ft_is_type.h"

int		calculate_data_int(t_params *prm, long long num)
{
	int digits;
	int length;

	length = 0;
	digits = count_digits(num, get_pos_number(prm));
	length -= (prm->prec == 0 && num == 0) ? 1 : 0;
	length += (num < 0) ? 1 : 0;
	length += digits;
	prm->zeros = get_positive(prm->prec - digits);
	length += prm->zeros;
	return (length);
}

int		check_integer(t_params *prm)
{
	int	length;

	length = 0;
	if (is_num(prm) || is_hob(prm) || is_ptr(prm))
	{
		if (is_ptr(prm))
			length += calculate_data_int(prm, prm->num_l);
		if (is_int(prm))
			length += calculate_data_int(prm, prm->num_i);
		if (is_hob(prm))
			length += calculate_data_int(prm, prm->num_l);
		if (is_uint(prm))
			length += calculate_data_int(prm, prm->num_u);
	}
	return (length);
}

int		check_string(t_params *prm)
{
	int			i;
	int			len;

	i = 0;
	if (is_str(prm) && prm->prec != 0)
	{
		len = ft_strlen(prm->str);
		if (prm->prec_exist)
		{
			if (prm->prec > len)
				i += len;
			else
				i += prm->prec;
		}
		else
			i += len;
	}
	return (i);
}

int		check_char(t_params *prm)
{
	int i;

	i = 0;
	if (is_chr(prm) || is_prc(prm))
	{
		i++;
	}
	return (i);
}

int		check_flags(t_params *prm)
{
	int length;

	length = 0;
	if (prm->flags & F_PLUS)
	{
		length++;
	}
	if ((prm->flags & F_SHARP) || is_ptr(prm))
	{
		if (is_hex(prm) || is_ptr(prm) || is_bin(prm))
		{
			length += 2;
		}
		if (is_oct(prm))
		{
			length += 1;
		}
	}
	return (length);
}

int		check_float(t_params *prm)
{
	if (is_float(prm))
	{
		if (!prm->prec_exist)
		{
			prm->prec = 6;
		}
	}
	return (0);
}

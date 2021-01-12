/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 10:56:32 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/16 18:13:19 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_printf.h"
#include "ft_is_type.h"
#include "ft_print_increment.h"

void	print_number_sign(t_params *prm, long long number)
{
	if (is_positive(number))
	{
		if (prm->flags & F_PLUS)
			ft_putchar_inc('+');
	}
	else
		ft_putchar_inc('-');
}

void	print_sign(t_params *prm)
{
	if (is_int(prm))
	{
		print_number_sign(prm, prm->num_i);
	}
	if (is_float(prm))
	{
		print_number_sign(prm, (prm->num_f.bits.sign == 0) ? 1 : -1);
	}
	if (prm->length & (LENGTH_LL | LENGTH_L))
	{
		print_number_sign(prm, prm->num_l);
	}
}

void	print_sharp(t_params *prm)
{
	if ((prm->flags & F_SHARP) || is_ptr(prm))
	{
		if (prm->type & (TYPE_X | TYPE_P))
			ft_putstrn_inc("0x", 2);
		if (prm->type & TYPE_XX)
			ft_putstrn_inc("0X", 2);
		if (prm->type & TYPE_B)
			ft_putstrn_inc("0b", 2);
		if (prm->type & TYPE_O)
		{
			if (!(prm->num_l == 0 || (prm->length & (LENGTH_L | LENGTH_LL) && prm->num_ul == 0)))
				ft_putstrn_inc("0", 1);
		}
	}
}

void	print_zero(t_params *prm)
{
	if (prm->flags & F_ZERO)
	{
		print_repeat('0', prm->spaces);
	}
}

void	print_space(t_params *prm)
{
	if (prm->flags & F_SPACE)
	{
		print_repeat(' ', 1);
	}
	if (!(prm->flags & F_ZERO) && prm->spaces > 0)
	{
		print_repeat(' ', prm->spaces);
	}
}

void	print_precision(t_params *prm)
{
	if ((prm->prec_exist) && !(prm->type & (TYPE_S | TYPE_C)))
	{
		print_repeat('0', prm->zeros);
	}
}

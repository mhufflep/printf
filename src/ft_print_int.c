/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 10:54:12 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/12 13:49:07 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_printf.h"
#include "ft_is_type.h"
#include "ft_print_itoa_base.h"
#include "ft_print_increment.h"

void	print_hexoctbin(t_params *prm)
{
	if (is_hob(prm) || is_ptr(prm))
	{
		if (prm->length & (LENGTH_L | LENGTH_LL))
		{
			if (!(prm->prec == 0 && prm->num_ul == 0))
			{
				ft_itoa_base(prm->num_ul, get_pos_number(prm), prm->type);
			}
		}
		else
		{
			if (!(prm->prec == 0 && prm->num_l == 0))
			{
				ft_itoa_base(prm->num_l, get_pos_number(prm), prm->type);
			}
		}
	}
}

void	print_integer(t_params *prm)
{
	if (is_int(prm))
	{
		if (prm->length & (LENGTH_L | LENGTH_LL))
		{
			if (!(prm->prec == 0 && prm->num_l == 0))
			{
				ft_putnbr_inc(prm->num_l);
			}
		}
		else
		{
			if (!(prm->prec == 0 && prm->num_i == 0))
			{
				ft_putnbr_inc(prm->num_i);
			}
		}
	}
}

void	print_unsigned(t_params *prm)
{
	if (is_uint(prm))
	{
		if (prm->length & (LENGTH_L | LENGTH_LL))
		{
			if (!(prm->prec == 0 && prm->num_ul == 0))
			{
				ft_putnbr_inc(prm->num_ul);
			}
		}
		else
		{
			if (!(prm->prec == 0 && prm->num_u == 0))
			{
				ft_putnbr_inc(prm->num_u);
			}
		}
	}
}

void	get_written_count(t_params *prm)
{
	long long count;

	if (is_ref(prm))
	{
		count = symbol_counter(0);
		if (prm->length == 0)
			*((long int *)prm->ref) = (long int)count;
		if (prm->length & LENGTH_HH)
			*((char *)prm->ref) = (char)count;
		if (prm->length & LENGTH_H)
			*((short *)prm->ref) = (short)count;
		if (prm->length & LENGTH_L)
			*((long int *)prm->ref) = (long int)count;
		if (prm->length & LENGTH_LL)
			*((long long *)prm->ref) = (long long)count;
	}
}

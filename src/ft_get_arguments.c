/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 02:36:14 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/09 22:30:16 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_is_type.h"

void	get_integer(t_params *prm, va_list ap)
{
	if (prm->length == 0)
		prm->num_i = va_arg(ap, int);
	if (prm->length & LENGTH_HH)
		prm->num_i = (char)va_arg(ap, int);
	if (prm->length & LENGTH_H)
		prm->num_i = (short)va_arg(ap, int);
	if (prm->length & LENGTH_L)
		prm->num_l = (long int)va_arg(ap, long int);
	if (prm->length & LENGTH_LL)
		prm->num_l = (long long)va_arg(ap, long long);
}

void	get_uinteger(t_params *prm, va_list ap)
{
	if (prm->length == 0)
		prm->num_u = (unsigned int)va_arg(ap, int);
	if (prm->length & LENGTH_HH)
		prm->num_u = (unsigned char)va_arg(ap, int);
	if (prm->length & LENGTH_H)
		prm->num_u = (unsigned short)va_arg(ap, int);
	if (prm->length & LENGTH_L)
		prm->num_ul = (unsigned long int)va_arg(ap, long long);
	if (prm->length & LENGTH_LL)
		prm->num_ul = (unsigned long long)va_arg(ap, long long);
}

void	get_reference(t_params *prm, va_list ap)
{
	prm->ref = va_arg(ap, void *);
	if (prm->length == 0)
		prm->ref = (long int *)prm->ref;
	if (prm->length & LENGTH_HH)
		prm->ref = (char *)prm->ref;
	if (prm->length & LENGTH_H)
		prm->ref = (short *)prm->ref;
	if (prm->length & LENGTH_L)
		prm->ref = (long int *)prm->ref;
	if (prm->length & LENGTH_LL)
		prm->ref = (long long *)prm->ref;
}

void	get_char(t_params *prm, va_list ap)
{
	if (prm->length & LENGTH_L)
		prm->chr = va_arg(ap, int);
	else
		prm->chr = (unsigned char)va_arg(ap, int);
}

void	get_pointer(t_params *prm, va_list ap)
{
	prm->num_l = va_arg(ap, long long);
}

void	get_hexoctbin(t_params *prm, va_list ap)
{
	if (prm->length == 0)
		prm->num_l = (unsigned int)va_arg(ap, int);
	if (prm->length & LENGTH_HH)
		prm->num_l = (unsigned char)va_arg(ap, int);
	if (prm->length & LENGTH_H)
		prm->num_l = (unsigned short)va_arg(ap, int);
	if (prm->length & LENGTH_L)
		prm->num_ul = (unsigned long int)va_arg(ap, long long);
	if (prm->length & LENGTH_LL)
		prm->num_ul = (unsigned long long)va_arg(ap, long long);
}

void	get_string(t_params *prm, va_list ap)
{
	prm->str = va_arg(ap, char *);
	if (prm->str == NULL)
	{
		prm->str = "(null)";
	}
}

void	get_float(t_params *prm, va_list ap)
{
	if (prm->length & LENGTH_LF)
		prm->num_f.num = va_arg(ap, long double);
	else
		prm->num_f.num = (double)va_arg(ap, double);
}

void	get_argument(t_params *prm, va_list ap)
{
	if (is_int(prm))
		get_integer(prm, ap);
	else if (is_ref(prm))
		get_reference(prm, ap);
	else if (is_float(prm))
		get_float(prm, ap);
	else if (is_chr(prm))
		get_char(prm, ap);
	else if (is_ptr(prm))
		get_pointer(prm, ap);
	else if (is_hob(prm))
		get_hexoctbin(prm, ap);
	else if (is_uint(prm))
		get_uinteger(prm, ap);
	else if (is_str(prm))
		get_string(prm, ap);
}

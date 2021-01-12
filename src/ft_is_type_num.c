/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 06:31:58 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/11 14:45:56 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_int(t_params *prm)
{
	return (prm->type & TYPE_I);
}

int		is_ref(t_params *prm)
{
	return (prm->type & TYPE_N);
}

int		is_uint(t_params *prm)
{
	return (prm->type & TYPE_U);
}

int		is_float(t_params *prm)
{
	return (prm->type & (TYPE_F | TYPE_G | TYPE_E));
}

int		is_num(t_params *prm)
{
	return (is_int(prm) || is_uint(prm));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 06:31:14 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/11 14:46:10 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_hex(t_params *prm)
{
	return (prm->type & (TYPE_X | TYPE_XX));
}

int		is_oct(t_params *prm)
{
	return (prm->type & TYPE_O);
}

int		is_bin(t_params *prm)
{
	return (prm->type & TYPE_B);
}

int		is_hob(t_params *prm)
{
	return (is_hex(prm) || is_oct(prm) || is_bin(prm));
}

int		is_ptr(t_params *prm)
{
	return (prm->type & TYPE_P);
}

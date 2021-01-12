/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_defaults.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 02:39:07 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/16 18:15:02 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_defaults(t_params *prm)
{
	prm->type = 0;
	prm->flags = 0;
	prm->width = 0;
	prm->prec = -1;
	prm->zeros = 0;
	prm->spaces = 0;
	prm->length = 0;
	prm->prec_exist = 0;
	prm->ref = 0;
	prm->str = 0;
	prm->chr = 0;
	prm->num_l = 0;
	prm->num_i = 0;
	prm->num_u = 0;
	prm->num_ul = 0;
	prm->num_f.num = 0.0f;
	prm->num_f.bits.sign = 0;
	prm->num_f.bits.exponent = 0;
	prm->num_f.bits.fraction = 0;
}

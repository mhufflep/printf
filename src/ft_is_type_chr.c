/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type_chr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 06:20:34 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/11 14:46:00 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_chr(t_params *prm)
{
	return (prm->type & TYPE_C);
}

int		is_prc(t_params *prm)
{
	return (prm->type & TYPE_PR);
}

int		is_str(t_params *prm)
{
	return (prm->type & TYPE_S);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_parameters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 02:41:34 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/11 14:46:19 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modify_params(t_params *prm)
{
	prm->flags &= (prm->flags & F_PLUS) ? ~F_SPACE : prm->flags;
	prm->flags &= (prm->flags & F_LINE) ? ~F_ZERO : prm->flags;
	prm->flags &= (prm->prec_exist) ? ~F_ZERO : prm->flags;
}

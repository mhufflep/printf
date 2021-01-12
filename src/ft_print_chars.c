/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 10:58:11 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/11 14:52:46 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_is_type.h"
#include "ft_print_increment.h"

void	print_string(t_params *prm)
{
	int	len;

	if (is_str(prm))
	{
		len = ft_strlen(prm->str);
		if (prm->prec_exist && (prm->prec < len))
			ft_putstrn_inc(prm->str, prm->prec);
		else
			ft_putstrn_inc(prm->str, len);
	}
}

void	print_char(t_params *prm)
{
	if (is_chr(prm))
	{
		ft_putchar_inc(prm->chr);
	}
	if (is_prc(prm))
	{
		ft_putchar_inc('%');
	}
}

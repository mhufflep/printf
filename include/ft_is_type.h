/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 06:33:25 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/11 15:04:44 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IS_TYPE_H
# define FT_IS_TYPE_H

# include "ft_printf.h"

int		is_chr(t_params *prm);
int		is_str(t_params *prm);
int		is_num(t_params *prm);
int		is_int(t_params *prm);
int		is_hex(t_params *prm);
int		is_oct(t_params *prm);
int		is_bin(t_params *prm);
int		is_hob(t_params *prm);
int		is_ptr(t_params *prm);
int		is_prc(t_params *prm);
int		is_uint(t_params *prm);
int		is_float(t_params *prm);
int		is_ref(t_params *prm);

#endif

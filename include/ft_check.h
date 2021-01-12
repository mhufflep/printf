/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 02:28:23 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/11 15:01:54 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_H
# define FT_CHECK_H

# include "ft_printf.h"

int		check_char(t_params *prm);
int		check_flags(t_params *prm);
int		check_float(t_params *prm);
int		check_string(t_params *prm);
int		check_integer(t_params *prm);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parameters.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:14:25 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/11 06:16:18 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_PARAMETERS_H
# define FT_GET_PARAMETERS_H

# include "ft_printf.h"

int		get_type(char c, t_params *prm);
int		get_flags(const char *s, t_params *prm);
int		get_length(const char *s, t_params *prm);
int		get_width(const char *s, t_params *prm, va_list ap);
int		get_precision(const char *s, t_params *prm, va_list ap);

#endif

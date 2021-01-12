/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arguments.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 05:41:41 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/11 15:04:29 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_ARGUMENTS_H
# define FT_GET_ARGUMENTS_H

# include "ft_printf.h"

void	get_argument(t_params *prm, va_list ap);
void	get_char(t_params *prm, va_list ap);
void	get_float(t_params *prm, va_list ap);
void	get_string(t_params *prm, va_list ap);
void	get_pointer(t_params *prm, va_list ap);
void	get_integer(t_params *prm, va_list ap);
void	get_uinteger(t_params *prm, va_list ap);
void	get_reference(t_params *prm, va_list ap);
void	get_hexoctbin(t_params *prm, va_list ap);

#endif

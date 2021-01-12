/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 10:59:57 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/12 10:42:01 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_INT_H
# define FT_PRINT_INT_H

# include "ft_printf.h"

void	print_float(t_params *prm);
void	print_hexoctbin(t_params *prm);
void	print_oct(t_params *prm);
void	print_hex(t_params *prm);
void	print_binary(t_params *prm);
void	print_integer(t_params *prm);
void	print_unsigned(t_params *prm);
void	get_written_count(t_params *prm);

#endif

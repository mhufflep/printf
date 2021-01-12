/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 11:02:50 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/11 06:16:47 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_FLAGS_H
# define FT_PRINT_FLAGS_H

# include "ft_printf.h"

void	print_sign(t_params *prm);
void	print_zero(t_params *prm);
void	print_space(t_params *prm);
void	print_sharp(t_params *prm);
void	print_precision(t_params *prm);

#endif

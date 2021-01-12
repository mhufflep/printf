/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_floats.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 01:42:18 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/14 20:58:28 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_FLOATS_H
# define FT_PRINT_FLOATS_H

# include "ft_printf.h"

//DELETE
# include <stdio.h>

void            print_float(t_params *prm);
int				get_exponent(t_params *prm);
// unsigned int	sum_bits(unsigned int fraction);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:20:23 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/12 13:59:15 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include "ft_printf.h"

int		is_positive(long long number);
int		get_positive(int number);
int		get_pos_number(t_params *prm);
int		print_repeat(char symbol, int count);
int		count_digits(long long number, unsigned int pos);
void	ft_itoa_base(unsigned long long n, unsigned int pos, short type);

#endif

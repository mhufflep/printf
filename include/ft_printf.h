/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 19:11:26 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/09 22:20:44 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# include "libft.h"

# define F_ZERO		0b00000001
# define F_PLUS		0b00000010
# define F_LINE		0b00000100
# define F_SPACE	0b00001000
# define F_SHARP	0b00010000

# define LENGTH_LL	0b00000001
# define LENGTH_L	0b00000010
# define LENGTH_H	0b00000100
# define LENGTH_HH	0b00001000
# define LENGTH_LF	0b00010000

# define TYPE_C		0b0000000000000001
# define TYPE_E		0b0000000000000010
# define TYPE_F		0b0000000000000100
# define TYPE_G		0b0000000000001000
# define TYPE_I		0b0000000000010000
# define TYPE_N		0b0000000000100000
# define TYPE_O		0b0000000001000000
# define TYPE_P		0b0000000010000000
# define TYPE_S		0b0000000100000000
# define TYPE_U		0b0000001000000000
# define TYPE_X		0b0000010000000000
# define TYPE_XX	0b0000100000000000
# define TYPE_PR	0b0001000000000000
# define TYPE_B		0b0010000000000000

typedef struct			s_bits
{
	unsigned long long  fraction : 64;
	unsigned int		exponent : 15;
	unsigned int		sign : 1;
}						t_bits;

typedef union			u_flt
{
	long double			num;
	t_bits				bits;
}						t_union;

typedef struct			s_params
{
	int					prec;
	short				type;
	char				flags;
	int					zeros;
	int					width;
	int					spaces;
	char				length;
	char				prec_exist;

	int					chr;
	char				*str;
	void				*ref;
	int					num_i;
	t_union				num_f;
	long long			num_l;
	unsigned int		num_u;
	unsigned long long	num_ul;
}						t_params;

int						ft_printf(const char *s, ...);

#endif

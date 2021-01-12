/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_itoa_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 02:48:24 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/14 06:27:08 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_print_increment.h"

void	ft_itoa_base(unsigned long long n, unsigned int pos, short type)
{
	char base;

	base = (type == TYPE_X || type == TYPE_P) ? 'a' : 'A';
	if (n / pos != 0)
		ft_itoa_base(n / pos, pos, type);
	ft_putchar_inc((n % pos < 10 ? n % pos + '0' : (n % pos) - 10 + base));
}

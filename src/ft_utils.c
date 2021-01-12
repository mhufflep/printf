/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:19:54 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/12 13:59:03 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_is_type.h"
#include "ft_print_increment.h"

int		count_digits(long long number, unsigned int pos)
{
	int	count;

	count = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number = number / pos;
		count++;
	}
	return (count);
}

int		get_positive(int number)
{
	return ((number < 0) ? 0 : number);
}

int		is_positive(long long number)
{
	return ((number < 0) ? 0 : 1);
}

int		get_pos_number(t_params *prm)
{
	int	pos;

	pos = 10;
	pos = (is_bin(prm)) ? 2 : pos;
	pos = (is_oct(prm)) ? 8 : pos;
	pos = (is_num(prm)) ? 10 : pos;
	pos = (is_hex(prm)) ? 16 : pos;
	pos = (is_ptr(prm)) ? 16 : pos;
	return (pos);
}

int		print_repeat(char symbol, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_putchar_inc(symbol);
		i++;
	}
	return (i);
}

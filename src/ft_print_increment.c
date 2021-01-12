/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_increment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:08:04 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/11 14:48:10 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		symbol_counter(int add)
{
	static int	count = 0;
	int			tmp;

	tmp = count;
	if (add == -1)
	{
		count = 0;
	}
	else
	{
		count += add;
	}
	return (tmp);
}

void	ft_putchar_inc(char c)
{
	symbol_counter(1);
	write(1, &c, 1);
}

void	ft_putstrn_inc(const char *str, int len)
{
	if (str)
	{
		write(1, str, len);
		symbol_counter(len);
	}
}

void	ft_putnbr_inc(long long int n)
{
	if (n < 0)
	{
		n *= -1;
	}
	if (n / 10 > 0)
	{
		ft_putnbr_inc(n / 10);
	}
	if (n % 10 >= 0 || n == 0)
	{
		ft_putchar_inc(((n % 10) + '0'));
	}
}

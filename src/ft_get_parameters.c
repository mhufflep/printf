/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parameters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 10:09:32 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/19 21:25:42 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_printf.h"

int		get_flags(const char *s, t_params *prm)
{
	int i;

	i = 0;
	while (ft_memchr("#0- +", s[i], 5))
	{
		prm->flags |= (s[i] == '-') ? F_LINE : 0;
		prm->flags |= (s[i] == '+') ? F_PLUS : 0;
		prm->flags |= (s[i] == '0') ? F_ZERO : 0;
		prm->flags |= (s[i] == ' ') ? F_SPACE : 0;
		prm->flags |= (s[i] == '#') ? F_SHARP : 0;
		i++;
	}
	return (i);
}

int		get_precision(const char *s, t_params *prm, va_list ap)
{
	int i;

	i = 0;
	if (s[i] == '.')
	{
		i++;
		if (s[i] == '*')
		{
			prm->prec = va_arg(ap, int);
			i++;
		}
		else
		{
			prm->prec = get_positive(ft_atoi(&s[i]));
			while (s[i] >= '0' && s[i] <= '9')
				i++;
		}
	}
	prm->prec_exist = (prm->prec >= 0) ? 1 : 0;
	return (i);
}

int		get_width(const char *s, t_params *prm, va_list ap)
{
	int i;

	i = 0;
	if (s[i] == '*')
	{
		prm->width = va_arg(ap, int);
		if (prm->width < 0)
		{
			prm->flags |= F_LINE;
			prm->width = -prm->width;
		}
		i++;
	}
	else
	{
		prm->width = ft_atoi(&s[i]);
		if (prm->width != 0)
		{
			i += count_digits(prm->width, 10);
		}
	}
	return (i);
}

int		get_length(const char *s, t_params *prm)
{
	int i;

	i = 0;
	if (s[i] == 'h')
	{
		i++;
		if (s[i] == 'h')
		{
			i++;
			prm->length |= LENGTH_HH;
		}
		else
			prm->length |= LENGTH_H;
	}
	else if (s[i] == 'l')
	{
		i++;
		if (s[i] == 'l')
		{
			i++;
			prm->length |= LENGTH_LL;
		}
		else
			prm->length |= LENGTH_L;
	}
	else if (s[i] == 'L')
	{
		i++;
		prm->length |= LENGTH_LF;
	}
	return (i);
}

int		get_type(char c, t_params *prm)
{
	char	*types;
	int		i;

	i = 0;
	types = "cefginopsuxX%b";
	c = (c == 'd') ? 'i' : c;
	while (types[i])
	{
		if (types[i] == c)
		{
			prm->type = (1 << i);
			return (1);
		}
		i++;
	}
	return (0);
}

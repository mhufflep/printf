/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_floats.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:29:02 by mhufflep          #+#    #+#             */
/*   Updated: 2020/12/19 23:00:08 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_is_type.h"
#include "ft_print_floats.h"
#include "ft_print_increment.h"

int         get_exponent(t_params *prm)
{
    //16382 if I get mantissa m∈[0;1] or 16383 if m∈[1;2]
    return (prm->num_f.bits.exponent - 16383);
}

long long	ft_pow(int pow, unsigned char base)
{
    long long res;
	
    res = 1;
    while (pow > 0)
    {
        res *= base;
        pow--;
    }
    return (res);
}

// long long mypow2(int pow)
// {
//     long long res;
//     res = 1;
//     while (pow > 0)
//     {
//         res *= 2;
//         pow--;
//     }
//     return (res);
// }

// long long   mypow10(int pow)
// {
//     long long res;
//     res = 1;
//     while (pow > 0)
//     {
//         res *= 10;
//         pow--;
//     }
//     return (res);
// }

// void        print_floats2(t_params *prm)
// {
//     long long rounded = (long long)prm->num_f.num;
//     double part = prm->num_f.num - (int)prm->num_f.num;
//     long long part_print = (part * mypow10(prm->prec + 1));
//     if (part_print % 10 >= 5)
//     {
//         part_print /= 10;
//         part_print++;
//     }
//     else
//     {
//         part_print /= 10;
//     }
//     ft_putnbr_inc(rounded);
//     ft_putchar_inc('.');
//     ft_putnbr_inc(part_print);
// }

void            mantissa(t_params *prm)
{
    unsigned long long mantissa;
    double fract;
    double sum;
    int i;

    i = 0;
    sum = 1;
    fract = 1;
    mantissa = prm->num_f.bits.fraction;
    while (i < 63)
    {
        fract /= 2;
        if ((mantissa >> (62 - i)) & 0x1)
        {
            sum += fract;
        }
        i++;
    }
}




void            print_type_f(t_params *prm)
{
    (void)prm;
}

void            print_type_g(t_params *prm)
{
    (void)prm;
}

void            print_type_e(t_params *prm)
{
    (void)prm;
}

void            print_float(t_params *prm)
{
    if (is_float(prm))
    {
        if (prm->num_f.bits.exponent == 0x7ff)
        {
            if (prm->num_f.bits.fraction == 0)
            {
                ft_putstrn_inc("inf", 3);
            }
            else
            {
                ft_putstrn_inc("nan", 3);
            }
        }
        else if (prm->num_f.bits.exponent == 0x0)
        {
            if (prm->num_f.bits.fraction == 0)
            {
                ft_putstrn_inc("0", 1);
            }
            else
            {
                // subnormals
				// the way to get subnormal's value is to sum all divisions
				// of each bit by the 2 to the power corresponding 
				// to the ordinal number of current bit.  
            }
        }
        else
        {
            if (prm->type & TYPE_F)
                print_type_f(prm);
            else if (prm->type & TYPE_G)
                print_type_g(prm);
            else
                print_type_e(prm);
            // mantissa(prm);
        }
    }
}
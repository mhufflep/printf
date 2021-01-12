#include "ft_printf.h"
#include "ft_print_floats.h"
#include "ft_check.h"

#define BASE 1000000000
#define SIZE 10

long long mypow2(int pow)
{
	long long res;
	
	res = 1;
	while (pow > 0)
	{
		res *= 2;
		pow--;
	}
	return (res);
}

long long mypow10(int pow)
{
	long long res;
	
	res = 1;
	while (pow > 0)
	{
		res *= 10;
		pow--;
	}
	return (res);
}


void	bigintClear(long long digits[])
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		digits[i] = 0;
		i++;
	}
}

void	bigintFill(long long x, long long digits[])
{                     
	int next;
	
	next = 0;
	while (x) 
	{
		digits[next++] = x % BASE;
		x /= BASE;
	}
}

#include <math.h>

int main(void)
{
	t_params prm;
	prm.num_f.num = 123.45f;
	int exp = get_exponent(&prm);
	
	long long whole_part = prm.num_f.bits.fraction;

	//long long whole[SIZE];
	//long long fract[SIZE];

	//printf("exp:%d\n", exp);
	//bigintClear(whole);
	long long copy = prm.num_f.bits.fraction;

	double num = ((double)prm.num_f.bits.fraction / (double)mypow2(52 - exp)) + mypow2(exp);
	double num2 = 123345.45678f;
	int r = (int)num2;
	double part = num2 - (int)num2;
	int prec = 3;
	long long k = mypow10(prec);
	long long part_print = (part * mypow10(prec));
	//printf("|%f|whole:%d|part:%lld|\n", num2, r, part_print);
	
	
	// 0011 0011 0000 1100 <m> <s>
	// ft_printf("%lld|%#llb\n", copy, copy);
	// ft_printf("%lld|%#llb\n", copy >> (51 - exp), copy >> (51 - exp));
	// bigintFill(copy >> (51 - exp), whole);

	// int i = 0;
	// while (i < SIZE)
	// {
	// 	printf("%lld\n", whole[i]);
	// 	i++;
	// }
	return (0);
}

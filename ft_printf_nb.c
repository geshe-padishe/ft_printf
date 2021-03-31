#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int nb_digites(long long nb, int base)
{
	int nb_digits;

	nb_digits = 1;
	while ((nb = nb / base) > 0)
		nb_digits++;
	return (nb_digits);
}

long long abs_value(long long nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void write_digits(long long nb, int base)
{
	int abs_base;

	abs_base = base;
	if (base < 0)
		abs_base = -base;
	if (nb >= abs_base)
		write_digits(nb / abs_base, base);
	if (base == 16)
		write(1, &"0123456789abcdef"[nb % 16], 1);
	else if (base == -16)
		write(1, &"0123456789ABCDEF"[nb % 16], 1);
	else if (base == 8)
		write(1, &"01234567"[nb % 8], 1);
	else
	   write(1, &"0123456789"[nb % 10], 1);
}

int print_nb_options(char *flags, int base, long long nb)
{
	if (base == 16)
		if (flags[0] == 1)
			write(1, "0x", 2);
	if (base == -16)
		if (flags[0] == 1)
			write(1, "0X", 2);
	if (base == 10)
	{
		if (flags[4] == 1)
		{
			if (nb > 0)
				write(1, " ", 1);
			else
				return (0);
		}
		if (flags[3] == 1)
			if (nb > 0)
				write(1, "+", 1);
		return (1);
	}
	return (2);
}

int options_length(char *flags, int base, long long nb)
{
	if (base == 16)
		if (flags[0] == 1)
			return (2);
	if (base == -16)
		if (flags[0] == 1)
			return (2);
	if (base == 10)
	{
		if (flags[4] == 1)
		{
			if (nb > 0)
				return (1);
			else
				return (0);
		}
		if (flags[3] == 1)
		{
			if (nb > 0)
				return (1);
			else if (nb < 0)
				return (1);
		}
	}
	return (0);
}
//BEFORE PRINT_NB PUT PRECISION TO NB_DIGITS+1
void print_nb(long long nb, int base, conv whoopty)
{
	long long nb_s;
	int nb_digits;
	int abs_base;

	nb_digits = 1;
	abs_base = abs_value(base);
	nb_s = abs_value(nb);
	if (nb < 0)
		write(1, "-", 1);
	nb_digits = nb_digites(nb, abs_base);
	while (whoopty.precision >= nb_digits)
	{
		write(1, "0", 1);
		whoopty.precision--;
	}
	nb_s = abs_value(nb);
	write_digits(nb_s, base);
}

int main(int argc, char **argv)
{
	long long nb;
	int base;

	(void)argc;
	nb = (long long)atoi(argv[1]);
	base = atoi(argv[2]);
	printf("nb = %lld\n", nb);
	printf("base = %d\n", base);
	printf("\n%020.5lld\n", nb);
}

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void write_digits(long long nb, int base)
{
	int abs_base;

	if (base < 0)
		abs_base = -base;
	else
		abs_base = base;
	if (nb >= base)
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

void print_nb(long long nb, int base, int precision, int length_modifier)
{
	long long nb_s;
	int nb_digits;
	int abs_base;
	
	(void)length_modifier;
	nb_digits = 1;
	nb_s = nb;
	if (base < 0)
		abs_base = -base;
	else
		abs_base = base;
	while ((nb_s = nb_s / abs_base) > 0)
		nb_digits++;
	while (precision > nb_digits)
	{
		write(1, "0", 1);
		precision--;
	}
	write_digits(nb, base);
}

int main(int argc, char **argv)
{
	int nb;
	int base;

	(void)argc;
	nb = atoi(argv[1]);
	base = atoi(argv[2]);
	print_nb(nb, base, 13, 0);
}

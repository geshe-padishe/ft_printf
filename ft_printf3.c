#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int print_nb_options(char *flags, int base, long long nb)
{
	if (base == 16)
		if (flag[0] == 1)
			write(1, "0x", 2);
	if (base == -16)
		if (flag[0] == 1)
			write(1, "0X", 2);
	if (base == 10)
	{
		if (flag[4] == 1)
			if (nb > 0)
				write(1, " ", 1);
			else
				return (0);
		if (flag[3] == 1)
			if (nb > 0)
				write(1, "+", 1);
		return (1);
	}
	return (2);
}

int opt_len(char *flags, int base, long long nb);
{
	if (base == 16)
		if (flag[0] == 1)
			return (2);
	if (base == -16)
		if (flag[0] == 1)
			return (2);
	if (base == 10)
	{
		if (flag[4] == 1)
			if (nb > 0)
				return (1);
			else
				return (0);
		if (flag[3] == 1)
		{
			if (nb > 0)
				return (1);
			else if (nb < 0)
				return (1);
		}
	}
	return (0);
}

int regulator(char *flags, int base, int precision, int *fld_wdt)
{
	if (flags[0])
		if (!(conversion == 'x' || conversion == 'X' || conversion == 'o'))
			return (1);
	if (flags[4] && flags[3])
		return (1);
	if (flags[1] && precision > 0)
		flags[1] = 0;
	if (flags[2])
		*field_width = -*field_width;
	if (conversion == 'x')
		base = 16;
	if (conversion == 'X')
		base = -16;
	if (conversion == 'o')
		base = 8;
	if (conversion == 'd' || conversion == 'i')
		base = 10;
	return (0);
}

int length_regulator(int fld_wdt, int precision, int nb_digits, char *flags)
{
	int fld_len_s;
	int nb_len;
	int opt_len;
	
	opt_len = opt_len(flags, base, nb);
	nb_len = precision;
	if (nb_digits > precision)
		nb_len = nb_digits;
	fld_len_s = abs_value(fld_wdt);
	if (fld_len_s > precision + opt_len(flags, base, nb))
	{
		if (fld_wdt > 0)
		{
			while (fld_len_s > nb_len + opt_len)
			{
				write(1, " ", 1);
				fld_len_s--;
			}
			print_nb(nb, base, precision, length_modifier);
		}
		else
		{
			print_nb(nb, base, precision, length_modifier);
			while (fld_len_s > nb_len + opt_len)
			{
				write(1, " ", 1);
				fld_len_s--;
			}
		}
	}
	else
		print_nb(nb, base, precision, length_modifier);
	return (0);
}

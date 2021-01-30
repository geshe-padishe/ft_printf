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
		{
			if (nb > 0)
				write(1, "+", 1);
			else if (nb < 0)
				write(1, "-", 1);
		}
		return (1);
	}
	return (2);
}
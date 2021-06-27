#include "ft_printf.h"

int	ft_small_nb(int nb1, int nb2)
{
	if (nb1 < 0)
		return (nb2);
	if (nb2 < 0)
		return (nb1);
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

int	nb_digites(long long nb, int base)
{
	int	nb_digits;

	nb_digits = 1;
	nb = nb / base;
	while (nb > 0)
	{
		nb = nb / base;
		nb_digits++;
	}
	return (nb_digits);
}

int	nb_undigites(unsigned long nb)
{
	int	nb_digits;

	nb_digits = 1;
	nb = nb / 16;
	while (nb > 0)
	{
		nb = nb / 16;
		nb_digits++;
	}
	return (nb_digits);
}

long long	abs_value(long long nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	write_digits(long long nb, int base)
{
	int	abs_base;

	abs_base = base;
	if (base < 0)
		abs_base = -base;
	if (nb >= abs_base)
		write_digits(nb / abs_base, base);
	if (base == 16)
		charput(&"0123456789abcdef"[nb % 16], 1, 0);
	else if (base == -16)
		charput(&"0123456789ABCDEF"[nb % 16], 1, 0);
	else if (base == 8)
		charput(&"01234567"[nb % 8], 1, 0);
	else
		charput(&"0123456789"[nb % 10], 1, 0);
}

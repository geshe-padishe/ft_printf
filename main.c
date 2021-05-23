#include "ft_printf.h"

int main()
{
	ft_printf("%42c", 'v');
	printf("%%\n");
	printf("%42c", 'v');
	printf("%%\n");
}

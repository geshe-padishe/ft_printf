#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
//#include "libft.h"

void write_hex(unsigned long long nb)
{
	if (nb > 15)
		write_hex(nb / 16);
	write(1, &"0123456789abcdef"[nb % 16], 1);
}

int main()
{
	int integer;
	char string[10] = "blablabla";
	char *pointer;
	int number2;
	double number;
	char *ptr;

	pointer = string;
	integer = 130000;
	number = 223007896.553719;
	number2 = -223878152;
	ptr = (char*)malloc(4);

//	printf("------------------------------------------\n");
//	//printf("%% %d, %.2s, %p\n", integer, string, pointer);
//	printf("gloat ' : %'g\n", number);
//	printf("float ' : %'f\n\n", number);
//
//	printf("eloat .0 : %.0e\n", number);
//	printf("gloat .0 : %.0g\n", number);
//	printf("float .0 : %.0f\n\n", number);
//
//	printf("eloat .1 : %.1e\n", number);
//	printf("gloat .1 : %.1g\n", number);
//	printf("float .1 : %.1f\n\n", number);
//
//	printf("eloat .2 : %.2e\n", number);
//	printf("gloat .2 : %.2g\n", number);
//	printf("float .2 : %.2f\n\n", number);
//
//	printf("eloat no prec: %e\n", number);
//	printf("gloat no prec: %g\n", number);
//	printf("float no prec: %f\n\n", number);
//
//	printf("eloat .10: %.10e\n", number);
//	printf("gloat .10: %.10g\n", number);
//	printf("float .10: %.10f\n\n", number);
//
//	printf("eloat .20: %.20e\n", number);
//	printf("gloat .20: %.20g\n", number);
//	printf("float .20: %.20f\n", number);
//
//	printf("----------------------'---------------------\n");
//
//	printf("'.10e: flag ''' bad behavior with 'e'\n");
//	printf("'.10d: %'.10d\n", number2);
//	printf("'.10g: %'.10g\n", number);
//	printf("'.10f: %'.10f\n", number);
//	setlocale(7, "LC_NUMERIC");
//	printf("localeconv(3): \"%c\"\n", *(localeconv()->thousands_sep));
//
//	printf("---------------------o-octal-----------------\n");
//
//	printf("+o: + undefined with o\n");
//	printf(" o: ' ' undefined with o\n");
//	printf("0o: 0 undefined with o\n");
//	printf("-o: %-o\n", integer);
//	printf("#o: %#o\n", integer);
//	printf("#-o: %-#o\n", integer);
//	printf("-15.10o: %-15.10o\n", integer);
//	printf("15.10o: %15.10o\n", integer);
//	printf("#.10o: %#.10o\n", integer);
//	printf("0.10o: %0.10o\n", integer);
//
//	printf("-----------first-flag-combinations---------------\n");
//
//	printf("-0: - overrides 0");
//	printf("0#x: %#x\n", integer);
//	printf("-#x: %-#x\n", integer);
//	printf(" 0d: % 0d\n", integer);
//	printf("+0d: % 0d\n", integer);
//
	printf("-------------------My-stuff-----------------------\n");
	long address;
	long long address2;

	address = (long)ptr;
	address2 = (long long)ptr;
	address2 = -0;
	printf("address2 hex: %#.10llx\n", address2);	

	dprintf(1, "address2 hex: 0x");
	write_hex(address2);
	printf("\n");
	//str = ft_itoa(address);
	//printf("address: %lu\n", address % 16);
	//address = address / 16;
	//printf("address: %lu\n", address % 16);
	//address = address / 16;
	//printf("address: %lu\n", address % 16);
	//address = address / 16;
	//printf("address: %lu\n", address % 16);
	//address = address / 16;
	//printf("address: %lu\n", address % 16);
	//address = address / 16;
	//printf("address: %lu\n", address % 16);
	//printf("str: %s\n", str);

}

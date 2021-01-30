#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
//#include "libft.h"

void write_hex(unsigned long long nb, char *nb_str)
{
	if (nb > 15)
		write_hex(nb / 16, nb_str + 1);
	//ft_strncpy("0123456789abcdef"[nb % 16], nb_str);
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
	printf("address2 hex: %#.10llx\n", address2);	

	dprintf(1, "address2 hex: 0x");
//	write_hex(address2);
	printf("\n");
	printf("%% :% d\n", number2);
	printf("%#.30llx\n", address2);
	printf("octal: %#.20llo\n", address2);
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

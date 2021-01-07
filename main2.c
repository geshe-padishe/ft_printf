#include <stdio.h>
#include <string.h>

int main()
{
	int integer;
	char string[10] = "blablabla";
	char *pointer;
	double number;

	pointer = string;
	integer = 130000;
	number = 21.83719;

	printf("------------------------------------------\n");
	//printf("%% %d, %.2s, %p\n", integer, string, pointer);
	printf("eloat .20: %.20e\n", number);
	printf("gloat .20: %.20g\n", number);
	printf("float .20: %.20f\n\n", number);

	printf("eloat only . : %.e\n", number);
	printf("gloat only . : %.g\n", number);
	printf("float only . : %.f\n\n", number);

	printf("eloat .0 : %.0e\n", number);
	printf("gloat .0 : %.0g\n", number);
	printf("float .0 : %.0f\n\n", number);

	printf("eloat .1 : %.1e\n", number);
	printf("gloat .1 : %.1g\n", number);
	printf("float .1 : %.1f\n\n", number);

	printf("eloat .2 : %.2e\n", number);
	printf("gloat .2 : %.2g\n", number);
	printf("float .2 : %.2f\n\n", number);

	printf("eloat no prec: %e\n", number);
	printf("gloat no prec: %g\n", number);
	printf("float no prec: %f\n\n", number);
}

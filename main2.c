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
	number = 2.553719;
	//number = 22;

	printf("------------------------------------------\n");
	//printf("%% %d, %.2s, %p\n", integer, string, pointer);
	printf("gloat ' : %'g\n", number);
	printf("float ' : %'f\n\n", number);

	printf("eloat .0 : %.0e\n", number);
	printf("gloat .0 : %.0g\n", number);
	printf("float .0 : %.0f\n\n", number);

	printf("eloat .1 : %.1e\n", number);
	printf("gloat .1 : %.1g\n", number);
	printf("float .1 : %.1f\n\n", number);

	printf("eloat .2 : %.2e\n", number);
	printf("gloat .2 : %.2g\n", number);
	printf("float .2 : %.2f\n\n", number);

	printf("eloat .3 : %.3e\n", number);
	printf("gloat .3 : %.3g\n", number);
	printf("float .3 : %.3f\n\n", number);

	printf("eloat .4 : %.4e\n", number);
	printf("gloat .4 : %.4g\n", number);
	printf("float .4 : %.4f\n\n", number);

	printf("eloat .5 : %.5e\n", number);
	printf("gloat .5 : %.5g\n", number);
	printf("float .5 : %.5f\n\n", number);

	printf("eloat no prec: %e\n", number);
	printf("gloat no prec: %g\n", number);
	printf("float no prec: %f\n\n", number);

	printf("eloat .10: %.10e\n", number);
	printf("gloat .10: %.10g\n", number);
	printf("float .10: %.10f\n\n", number);

	printf("eloat .20: %.20e\n", number);
	printf("gloat .20: %.20g\n", number);
	printf("float .20: %.20f\n", number);

	printf("------------------------------------------\n");
	int number2;
	number2 = -22;

	printf("unisgned hex float: %x\n", number2);
	printf("unsigned capital float hex: %X\n\n", number2);

	printf("unsigned alternate hex: %#x\n",number2);
	printf("unsigned capitacal alternate hex: %#X\n",number2);
}

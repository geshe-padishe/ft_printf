#include <stdio.h>
#include <string.h>

int main()
{
	int integer;
	char string[10] = "blablabla";
	char *pointer;

	pointer = string;
	integer = 130000;
	printf("%% %d, %.2s, %p\n", integer, string, pointer);
}

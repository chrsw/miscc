// printf_args.c
//

#include <stdio.h>

int main(void) {

	int width, num;
	width = 4;
	num = 3;

	printf("%*d\n", width, num);
	printf("%2$*1$d\n", width, num);
	return 0;
}

// scanf() example
//

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char s[40];
	int n;
	int res;

	res = scanf("%s %d", s, &n);
	printf("entered: %s %d\n", s, n);

	printf("length = %lu\n", strlen(s));
	return res;

}

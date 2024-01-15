/* vim:ts=4:sw=4:et:so=10:ls=2:
 * 
 * Simple scanf() example.
 */

#include <stdio.h>
#include <string.h>

/* scanf_ex:  get some input from keyboard and print it */
int main(int argc, char *argv[])
{
	char s[40];
	int n;
	int res;
    int x, y;

	res = scanf("%s %d", s, &n);
	printf("entered: %s %d\n", s, n);

	printf("length = %lu\n", strlen(s));

    printf("enter a point...\n");
    getchar();

    res = scanf("x %d y %d", &x, &y);
    printf("x = %d, y = %d\n", x, y);

	return res;

}

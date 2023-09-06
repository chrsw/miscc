// Find the length of an integer

#include <stdlib.h>

int main(int argc, char *argv[]) {

	int len = 1;
    int num = 0;

	if (argc > 1)
	    num = atoi(argv[1]);
	else
        return -1;

	while (num /= 10)
		len++;

	return len;
}

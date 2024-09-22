// hisleep:  Say hi then sleep for random amount of time
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[]) {

	int r;
	unsigned int s;

	printf("Hi!\n");

	s = (unsigned int)time(NULL);	
	srand(s);
	r = rand();
	r = r % 10;

	printf("Sleeping for %d\n", r);
	sleep(r);

	return 0;

}

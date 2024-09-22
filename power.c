// pow: 	calculate x raised to the power of y

unsigned long power(int x, int y) {

	unsigned long ulx, uly;
	int i = y;
	ulx = (unsigned long)x;
	uly = (unsigned long)y;

	if (!y) return (unsigned long)0;
	if (y == 1) return (unsigned long)1;

	for (i = y; i > 0; i-- ) {
		ulx = ulx * x;	
	}

	return 0;
}

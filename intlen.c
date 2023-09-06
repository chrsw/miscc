// Find the length of an integer

int i = 555;

int main(void) {

	int len = 1;
	int copy;

	copy = i;
	while (copy /= 10)
		len++;

	return len;
}

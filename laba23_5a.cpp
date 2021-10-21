#include <stdlib.h>
#include <stdio.h>
int main() {
	char* some_memory = (char*)0;
	printf("A read from null %sn", some_memory);
	sprintf(some_memory, "A write to nulln");
	exit(EXIT_SUCCESS);
}

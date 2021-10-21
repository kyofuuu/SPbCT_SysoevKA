#include <stdlib.h>
#include <stdio.h>
int main() {
	char z = *(const char*)0;
	printf("I read from location zeron");
	exit(EXIT_SUCCESS);
}
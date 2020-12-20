#include <stdio.h>
#include <stdlib.h>
#define SIZE 7
int main() {
	int level;
	int star, blank;
	for (level = 0; level < SIZE; level++) {
		printf("\t");
		for (blank = 0; blank < SIZE - level; blank++)
			printf(" ");
		for (star = 0; star < 2 * level - 1; star++)
			printf("*");
		printf("\n");
	}
	for (level = SIZE; level>0; level--) {
		printf("\t");
		for (blank = 0; blank < SIZE - level; blank++)
			printf(" ");
		for (star = 0; star < 2 * level - 1; star++)
			printf("*");
		printf("\n");
	}
	printf("\n\tToday is 12/20\n\n\tand I start new love X_X\n\n\n");
	return 0;
}

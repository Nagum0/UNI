#include <stdio.h>

char *cat(char *fileName);

int main(int argc, char *argv[]) {
	char *fileInfo = cat(argv[1]);
	printf("%s\n", fileInfo);

	return 0;
}

char *cat(char *fileName) {
	FILE *file = fopen(fileName, "r");

	
}
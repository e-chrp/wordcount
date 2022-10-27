#include <stdio.h>
#include <stdlib.h>

#define IN 1
#define OUT 0

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Usage: %s [file]\n", argv[0]);
		return 1;
	}

	FILE* file = fopen(argv[1], "r");
	if (file == NULL) {
		printf("No such file: \"%s\"\n", argv[1]);
		return 2;
	}
	
	_Bool state = OUT;
	char c;
	int cnt = 0;

	while ((c = fgetc(file)) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;

		else if (state == OUT) {
			state = IN;
			cnt++;
		}	
	}
	
	fclose(file);

	printf("The file \"%s\" contains %d words.\n", argv[1], cnt);

	return 0;
}

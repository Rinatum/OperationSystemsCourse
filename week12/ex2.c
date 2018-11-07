#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int main(int argc, char **argv){
	int length;
	char* op;
	if (argc == 1){
		printf("ONE ARG\n");
		char buf;
		while(fread(&buf, 1, 1, stdin))
			printf("%c",buf);
		return 0;
	}
	if (!strcmp(argv[1], "-a")){
		printf("CASE -A\n");
		length = argc - 1;
		op = "a+";
	}
	else{
		printf("CASE -W\n");
		length = argc;
		op = "w+";
	}

	FILE **buffer = malloc(length * sizeof(FILE*));
	buffer[0] = stdout;
	for(int i = 1; i < argc + 1; i++)
		buffer[i] = fopen(argv[i + argc - length], op);
	
	char buf[100];
	size_t size;
	while((size = fread(buf, 1, 100, stdin))){
		for(int j = 0; j < length; j++)
			for(int i = 0; i < size; i++)
				fwrite(&buf[i], 1, 1, buffer[j]);
	}

	for(int i = 1; i < length; i++)
		fclose(buffer[i]);
	return 0;
}

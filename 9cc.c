#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	if(argc < 2){
		fprintf(stderr, "Wrong arguments\n");
		return 1;
	}

	FILE *o;
	o = fopen("tmp.s", "w");
	

	fprintf(o, ".intel_syntax noprefix\n");
	fprintf(o, ".global main\n");
	fprintf(o, "main:\n");
	fprintf(o, "\tmov rax, %d\n", atoi(argv[1]));
	fprintf(o, "ret\n");
	return 0;
}


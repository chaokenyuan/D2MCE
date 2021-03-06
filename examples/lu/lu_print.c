/*
    SOR(successive over relaxation)
   	use to print data 
    version: 1.0
    date: 2008/6/18
    author: Zong Ying Lyu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RANDOM_SEED	3838
#define SIZE 1024
#define TYPE double
int print_usage()
{
	printf(" Usage: sor_print [options]\n");
	printf(" Option:\n");
	printf(" \t[ -s <vector size> ] (default: %d)\n", SIZE);
	printf(" \t[ -f <input file name> ]\n");

	return 1;
}
int main(int argc, char *argv[])
{
	int i,j;
	int n;
	double *data;
	FILE *file;
	char *name;
	n=SIZE;
	if (argc > 1) {
		for ( i = 1 ; i < argc ;) {
			if (strcmp(argv[i],"-s") == 0) {
				n = atoi(argv[i+1]);
				i+=2;
			} else if (strcmp(argv[i],"-f") == 0) {
				name = argv[i+1];
				i+=2;
			} else {
				print_usage();
				return 0;
			}
		}
	}
	data = malloc(sizeof(TYPE)* n * n);
	file = fopen(name,"r");
	if (file == NULL) {
		printf("can't not open file %s\n", name);
		return -1;
	}
	fread(data, sizeof(TYPE), n * n, file);
	fclose(file);
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			printf("%f ", data[i*n+j]);
		}
		printf("\n");
	}
	return 0;
}

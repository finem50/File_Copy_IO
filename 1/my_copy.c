/* input MUST be: %my_copy destination_file source_file */
/* MUST use the following: fopen(), fclose(), fread(), fwrite() */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]){

	FILE *file_in, *file_out;
	char buffer[BUF_SIZE];
	ssize_t file_r;

	/* Validate correct input from user */
	if(argc != 3){
		printf("Usage: ./main destination_file source_file\n");
		exit(-1);
	}
	
	/* Create file input and input validation */
	file_in = fopen(argv[2], "r");
	if (file_in == NULL){
		
		perror("Input File Error");
		exit(-1);
	}

	/* Create file output and input validation */
	file_out = fopen(argv[1], "w");
	if(file_out == NULL){

		perror("Output File Error");
		exit(-1);
	}

	/* Copy file contents from src (argv[2]) >> dst (argv[1]) */
	while(0 < (file_r = fread(buffer, 1, BUF_SIZE, file_in))){

		fwrite(buffer, 1, file_r, file_out);
	}

	fclose(file_in);
	fclose(file_out);
	return 0;
}

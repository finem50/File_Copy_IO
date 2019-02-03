/* input MUST be: %my_copy destination_file source_file */
/* MUST use the following: open(), close(), read(), write() */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]){

	int file_in, file_out;
	char buffer [BUF_SIZE];
	ssize_t file_r, file_w;

	/* Validate correct input from user */
	if(argc != 3){
		printf("Usage: ./main destination_file source_file\n");
		exit(-1);
	}

	/* Create file input and input validation */
	file_in = open(argv[2], O_RDONLY);
	if(file_in == -1){
		
		perror("Input File Error");
		exit(-1);
	}

	/* Create file output and input validation */
	file_out = open(argv[1], O_WRONLY | O_CREAT, 0600);
	if(file_out == -1){

		perror("Output File Error");
		exit(-1);
	}
		
	/* Copy file contents from src (argv[2]) >> dst (argv[1]) */
	while(0 < (file_r = read(file_in, &buffer, BUF_SIZE))){
		
		file_w = write(file_out, &buffer, (ssize_t) file_r);
		if(file_w != file_r){
		
			perror("File Copy Error");
			exit(-1);
		}
	}


	close(file_in);
	close(file_out);

	return 0;
}

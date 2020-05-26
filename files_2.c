/*
the purpose of this C progrram is to be able to open and read a file.
we won't be checking if the file exist using builf in libraies. instead we will jsut check if the file pointer is null


*/

  
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

void file_handler(FILE * file);
void file_handler_two(int fd);
//main
void main(){

	// openning the file, with reading permissions 
	// note that the file must esxist, otherwise this will return a null 
	FILE * my_file = fopen("data.txt","r");

	//read data from a file using the funtion fscanf();
	file_handler( my_file );

	// ill open the file in a different manner, in oder to create a file descriptor for the read()
	// the )_RDONLY and 0666 are jsut flags and access mode.
	int file_descriptor  = open("data.txt", O_RDONLY, 0666);

	file_handler_two( file_descriptor );

	// always remember to close all of your files.
	fclose(my_file);
	close(file_descriptor);
	
}// end of main

// this function read the fule using the function read()
// this requires that yoy know the size of the chunk, in this case i will only expect chunks of a byte: something like 11111110 hghdugye hellohel holahola holahola 
// REMERBER: the amamount read by read() is totally fixed. so any chunk that is not of the specifies size, will throw your sizing out of balance. 
// one solution is to write the file with no spacs aso that every read is done continous
void file_handler_two( int fd ){

	// this buff is where i will store the data read and then displayed in the stdout
	char buf[8];

	ssize_t bytes_read;
	
	//check if the file was openned porperly
	if(fd == -1){
		printf("File Error: file not found\n");
		exit(0);
	}

	// read the first  byte
	// the parameter 8 is the number of bites to expected to read: 8 bites  == 1 byte 
	// the fucntion returns the actual bytes read. so end of file will be 0(zero), this will be used to loop
	bytes_read =  read(fd, buf, 8);

	while( bytes_read != 0 ){
			
		// first print the data read. 
		printf("Data read; %s\n", buf);

		// second, read the next chunk
		bytes_read =  read(fd, buf, 8);
		
		
	}


}// end of function


// file handler
void file_handler(FILE * file){
	
	char data;

	if(file == NULL){
		
		printf("FILE Error: File not found\n");

		exit(0);

	}

	// let's read some data.
	//fscanf(file pointer , the type of data expexcted, the address of wherr to store it);
	// note that the var where the data is to be install needs to match what is comming from the file. so if you need to read a random file. simply use unassigned variables. and dont forget to flush
	fscanf(file, "%c", &data);

	// iterate throught the file until the end is read.
	while(!feof(file)){
		
		// first print the data: this can be to the std files or to regular file.
		// i will print to the screen using the  stdout
		fprintf(stdout, "Data: %c\n", data);

		// flush the stdout
		fflush(stdout);

		// read more data before looping
		fscanf(file, "%c", &data);
				
	}




}//end of file handler
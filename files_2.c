/*
the purpose of this C progrram is to be able to open and read a file.
we won't be checking if the file exist using builf in libraies. instead we will jsut check if the file pointer is null


*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void file_handler();
//main
void main(){
	//read data from a file using the funtion fscanf();
	file_handler();
	
}// end of main

// file handler
void file_handler(){
	
	char data;

	// openning the file, with reading permissions 
	// note that the file must esxist, otherwise this will return a null 
	FILE * my_file = fopen("data.txt","r");
	if(my_file == NULL){
		
		printf("FILE Error: File not found\n");

		exit(0);

	}

	// let's read some data.
	//fscanf(file pointer , the type of data expexcted, the address of wherr to store it);
	// note that the var where the data is to be install needs to match what is comming from the file. so if you need to read a random file. simply use unassigned variables. and dont forget to flush
	fscanf(my_file, "%c", &data);

	// iterate throught the file until the end is read.
	while(!feof(my_file)){
		
		// first print the data: this can be to the std files or to regular file.
		// i will print to the screen using the  stdout
		fprintf(stdout, "Data: %c\n", data);

		// flush the stdout
		fflush(stdout);

		// read more data before looping
		fscanf(my_file, "%c", &data);
				
	}

	// always remember to close you files.
	fclose(my_file);



}//end of file handler
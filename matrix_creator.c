/*
	
	Purpose of this program is to create a  NXN matrix or a 2D array populated with random numbers from 0 to 100 and print to a file. another prgram will take that text file and fork so one process read the file and the second performs matrix addition and then prints to another file.. 
	it will also tell how long it takes to do the matrix using native function from th library time.h

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function definitions
void matrix_create(int size);

// driver/ main
int main(int argc, char * argv[]){

	int size=0;

	// enhance the code so that the user has the option to either pass the size throug command line 
	// of during run time.
	// need to ask the user for desired matrix size
	// logic: if users passes size though commandline then the argc == 2 as in 
	//$./matrix size(as an int)
	// otherwise argc = 1 as in:
	// ./matrix (just the name of the executable) 
	if( argc == 2 ){

		size = atoi( argv[1] );

	}else{
		printf("Enter matrix sixe: ");

		scanf("%d", &size);
	}
	
	matrix_create(size);

}// end of main/driver

// matrix generator
void matrix_create(int size){
	
	time_t start, end, total=0;

	// start timer
	start = time(NULL);

	// open a file(Pointer) with writting permission
	FILE * my_file = fopen("jupiter.txt", "w");

	// check if the file openned successfully
	if(my_file == NULL){

		printf("File Erro: File failed to open\n");

		exit(0);
	}

	
	// 2d array
	int matrix[size][size];

	// needed to create random variables.
	// rand() generated the random variables, however w/o srand(), //rand() will generate the same random numbers per session
	srand(time(NULL));

	// counters will be used for formating
	// counter one will serve to print column
	// counter2 sill serve the rows
	int counter=0, counter2=0;

	// let's populate the matrix
	for(int i=0; i < size ; i++){
		for(int j = 0; j < size ; j++){

			// i want random numbers between 0 and 100
			matrix[i][j] = rand() % 100;

			if(counter == size){

				fprintf(my_file,"\n");

				counter =0;

			}

			// testing
			fprintf(my_file," %d ",matrix[i][j]);

			if(counter2 == size*size){
				fprintf(my_file, "\n");
			}

			counter++;
			counter2++;

		}// end of j loop
	}// end of i loop

	// stop the timer
	end = time(NULL);

	// print total time end - start
	printf("\nTime to execute: %ld miliseconds\n", (end - start));

}// end of matrix generator


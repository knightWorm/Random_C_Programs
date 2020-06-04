/*
	Purpose: this program is meant to read a matrix from an external file using one process, and perform matrix multiplication using the other process. the secon process will also be responsible saving the new matrix to another external file. this will also keep track of the time it takes to do the operation

*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void matrix_add(time_t start);
// main/driver
int main(){
	
	time_t start = time(NULL);
	printf("Start: %ld\n", start);

	// run matrix add
	matrix_add(start);




}// end of driver

//matrix add: this function will handle the following functions:
// creata the child process
// read from file
// perform matri addition
// save to file.
void matrix_add(time_t start){
	
	// this is where the nincoming info will be stored. 
	int status;

	// this will hold the numbers coming from the file.
	int *counter;

	// for pipe: feel free to look at my other code to seee how this one works
	int fd[2];

	//pipe for communication
	pipe(fd);


	// fork 
	pid_t child = fork();
	
	// When fork fails it return a negative number. no need to keep going if this part fails
	if(child < 0){

		printf("Fork failed \n");
		exit(0);
	}

	// now let's set this up in a way such that the child finishes first
	if(child == 0){
		// child process
		int k;

	// open the file to be read
	// motice that i am hardcoding the file name . you do not have to do it this way. its just an extension to anther program called matrix creaot. 
	FILE * my_file = fopen("jupiter.txt","r");

	if(my_file == NULL){
		printf("File failed to open\n");
		exit(0);
	}

	//let'sread the first int
	fscanf(my_file, "%d", &k);

	int i=0;

	// not lets look at the rest with a while loop
	while(!feof(my_file)){
		
		counter[i] = k;

		printf("Here is what we have in counter[%d] = %d", i, counter[i]);

		// read the next int 
		fscanf(my_file, "%d", &k);

		i++;

		fflush(stdout);

	}// end of while
	
	}else{

		waitpid(child, &status, 0);

		printf("I am parent\n");

		time_t end = time(NULL);
		printf("End: %ld \nTotal Time: %ld\n", end, (end - start));
	}

}// end of matrix ass
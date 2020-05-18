/*
	The purpose of this program is to further use the functiona fork(),
	and we will pass a message from one precess to the other. 

	BUILD:
	if you're using Ubunto

	$ cd /mnt/c/users/yourAccount/desktop/wherever you clone my repo
	$ gcc -o forking fork_2.c

	RUN:
	$ ./forking

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// main
int main(){
	
	// this is the file pointer that will go in the pipe:
	// 0 for reading 
	// 1 for writing 
	int fd[2];

	// for forking
	//  < 0; fork failed.
	//  == 0; child process
	// > 0; parent process
	pid_t pid;

	// this is for the state of the process which will bedetermined uby the the function waitpid()
	int status;

	// this is where the message will be stored.
	char buff[11];

	// let's pipe
	pipe(fd);

	// let's create a child process
	pid = fork();
	// no need to run any more code if the fork fails.
	// let's stop it here
	if(pid < 0 ){
		fprintf(stderr, "Fork failed\n");
	}

	// child process
	if(pid == 0){

		printf("Child is writting a message\n");

		// close the pipe end that is not being used. 
		close(fd[0]);

		// write to the pipe
		// the parameter are, file descriptor, fd[1]; 
		// the string to be written to the pipe, "Hello papa!"
		// bits in the string, our case 11;
		write(fd[1],"Hello Papa!", 11);


	}else{
		// parent processs

		waitpid(pid, &status, 0);

		// read from the pipe
		// paremeters are:
		// file descriptor, fd[1];
		// where to store teh string of char, buff; 
		// the amoiunt of bits comming form the pipe, 11;
		read(fd[0], buff, 11);

		printf("Child says: %s ", buff);

	}
	
}//end of main

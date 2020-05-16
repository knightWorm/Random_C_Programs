/*

The purpose of this program is to fork a second process that using the function fork();
this will only only for a child process and display a message before its parent process displays its meseage. 

test:
Build:
 $ cd your repo
 $ gcc -o exec forking.c

 RUN:
 $ ./exec

 OUTPUT:
 $ this is child, pid = whatever the child process id is
 $ this is parent, pid = whatever the child process id is

Note: later on i will expend on this program in another source file. feel free to look in my repo for it. 


i hopw thia helped you in your program. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// main
int main(){

	// this will store the process id for both parent and child 
	pid_t pid;

	// this will store the state of the processs. its possible outcomes are: 0 for success and -1 for failure 
	int status;

	// Let's fork a child process
	pid = fork();

	// When fork() fails it returns a negative integer.
	if(pid < 0){
		fprintf(stderr,"Fork Failed pid = %d", pid);
		exit(0);
	}

	// child process  == 0
	if(pid == 0){
		//getpid() return the current process id.
		printf("This is Child, pid = %d\n", getpid());

	}else{

		/* This is the parent process */

		// waitpid() is meant to allow the the child proccess execute first. while storing its state in the variable status.
		// this can be changed. thi is done in the options parameter
		// if you don't use this function. your process will be accessed differently.
		// feel free to look at waitpid(2) man pages for more information
		// for now it will be used with option 0 to allow the child to terminate first. 
		waitpid(pid, &status, 0);
		printf("This is parent, pid = %d\n", getpid());

	}


}// end of main
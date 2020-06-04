#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// main
int main(){
	
	pid_t pid = fork();
	int status;
	if(pid == 0){
		
		printf("this is cchild\n");

	}else{
	    
	    waitpid( pid , &status , 0 );
		printf("This is parent\n");
	
	}

}
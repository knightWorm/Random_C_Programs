/*
This program is meant to print everything passed through the command line, and stored in a buffer.
Running;
$ gcc -o whateverNameYouWant commandLinePrint.c
$ ./whateverNameYouWant p1 p2 p3 p4 p5 p6 p7 p8 p9 p10

outout:
$ ./whateverNameYouWant
$ Data: p1
$ Data: p2
$ Data: p3
$ Data: p4
$ Data: p5
$ Data: p6
$ Data: p7
$ Data: p8
$ Data: p9
$ Data: p10

i hope this help in your program. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//main
int main(int argv, char * args[]){
	
	char  * buf[argv];

	for(int i = 0; i < argv; i++){

		// store content in a buffer: 
		buf[i] = args[i];

		//printing the data
		printf("Data: %s\n",args[i]);


	}

	
}//end of main
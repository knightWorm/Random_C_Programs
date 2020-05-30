/*
	the purpose of this program is to open a file for writting. latter on we will read the same file from another program.
	to teach you how to open a file using C programming. 
	The program will have 2 options, either the program asks for the name of the file you want to creata, or you will pass it form the command line.
	also we will write the following msg: Thanks for looking at my repo, i hope this helped with any of your assignments. 

	BUILD:
	use ither mac or subsystem Ubunto 

	for mac:
	open terminal.
	$ cd desktop
	$ cd nameofyourdir
	$ gcc -o file files.c

	for Ubunto:
	open ubunto
	$ cd mnt/c
	$ cd users/yourusername/desktop/nameOfYourDir
	$ $ gcc -o file files.c

	RUN:
	./file --> for the system to ask you for the file name

	or 
	./file nameOfFile.txt

	NOTE: if you want to extend the file name, make it longer, simply chnage the the buf[10] to buf[whatever int you want.]

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// driver/main
// the driver will handle the logic as to which program execute
void file_handle_no_term();
void file_handle_with_term(char * file_name);
int main( int argv, char * argc[] ){
	
	// i am not expecting anything other than the file name, so if more than two things are being passed to the command line, the program will jsut terminate. 
	if(argv > 2){

		printf("Error: ainvalid input\n");

	}
	
	// == 1 because this means that the only thing given in the command 
	// line was the name of your excutable
	// in this case it will be: ./file. I.e. ./file --> argc[0] = ./file
	// NOTE: you do not need to format your loic this way. 
	// instead of having two function. you can jsut use one that has similar logic inside of it.
	// simply check the amount of items passed throught the commandline and execute based on that.
	// if that sounds confusing check my other source file called matrix-creator.c lines 27-35
	if(argv == 1 ){

		file_handle_no_term();

	}else{

		file_handle_with_term(argc[1]);

	}

}//end of main

// this function will open and create the file based but will as the user to enter the file name with the file extension. 
void file_handle_no_term(){
	
	// the max of letter for the name including the extension wil be 10
	char buf[10];
	
	// getting file name from users 
	printf("Enter file name: ");
	scanf("%s", buf);

	//opening the file
	// buff wil be the file name
	// "r" is the persmission given to that file. here we  r is for writing
	FILE * my_file = fopen(buf, "w");

	// now let's write to the file
	// i m goint to use fprintf() istead of fwrite() or write(), becasue i dont want to iterate
	fprintf(my_file, "Thanks for looking at my repo, i hope this helped with any of your assignments.");

	// always close your files when you are done. 
	fclose(my_file);

}// end of file_handle_no_term

// this function will handdle the file name that comes from the commandline.
void file_handle_with_term(char * file_name){


	//opening the file
	// buff wil be the file name
	// "r" is the persmission given to that file. here we  r is for writing
	FILE * my_file = fopen(file_name, "w");

	// now let's write to the file
	// i m goint to use fprintf() istead of fwrite() or write(), becasue i dont want to iterate
	fprintf(my_file, "Thanks for looking at my repo, i hope this helped with any of your assignments.");

	// always close your files when you are done. 
	fclose(my_file);


}// end of file_handle_with_term


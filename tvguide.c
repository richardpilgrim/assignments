#include <stdio.h>
#include "user_interface.h"

int main(int argc, char **argv){
	if(argc == 3){//Checks if the user has included an input and output file
		userInterface(argv[1], argv[2]);
		return 0;
	}
	else
	{
		fprintf(stderr, "You need an input and output file\n");//Prints to the standard error file in UNIX
		return -1;
	}
}

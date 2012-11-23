#include <stdio.h>
#include "user_interface.h"
#include "string.h"
#include "boolean.h"

void userInterface(char *input, char *output){
char day[10];
int valid = FALSE;
while (!valid){

printf("Please enter the name of the day you would like to display in lower case (eg tuesday):");
scanf("%9s",day);
if ((strcmp(day,"monday")==0)||(strcmp(day,"tuesday")==0)||(strcmp(day,"wednesday")==0)||(strcmp(day,"thursday")==0)||(strcmp(day,"friday")==0)||(strcmp(day,"saturday")==0)||(strcmp(day,"sunday")==0))//If the day does not equal these then asks for input again
{
	valid = TRUE;
}
}

char option[5];
valid = FALSE;
while(!valid){

printf("Would you like to sort the TV Guide by time or name:"); 
scanf("%s",option);
if ((strcmp(option,"time")==0)||(strcmp(option,"name")==0))//If day does not equal this then asks for input again
{
	valid=TRUE;
}


}
printf("Day is: %s\n",day);
printf("Option is: %s\n",option);
loadFile(input, day, option, output);//Sends to loadFile

}


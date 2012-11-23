#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "linked_list.h"
#include "comparison.h"

void outputFile(Entry *array,int length,char *output){
	int x;
	FILE* f = fopen(output, "w");
	for (x=0;x<length;x++){//Prints to the screen then to the output file
		printf("%s - %s", (array[x].time),(array[x].title));
		fprintf(f, "%s - %s", (array[x].time),(array[x].title));
	}
	fclose(f);
}

void loadFile(char *input, char *uday, char *uoption, char *output)
{

		FILE* f = fopen(input, "r");
		if(f==NULL)
		{
			perror("Error opening input file");
		}
		else
		{
			LinkedList *list = createList();
			do
			{
				char title[80];
				char day[10];
				char time[6];
				fgets((title),80,f);
				fscanf(f, "%s %s\n", day, time);
				if (ferror(f)){
				perror("Error reading from input file\n");
				}
				
				if (strcmp(day,uday)==0){//If the day is the same as the entrys file then copy it to the data structure
					Entry* entry = (Entry*)malloc(sizeof(Entry));
					strncpy((entry->title),title, 80);//Copies the strings read above to the data structure instead of reading the file twice
					if(time[1]==':'){
						snprintf(entry->time,6," %s",time);
					}
					else{
					strncpy((entry->time), time, 6);
					}
					strncpy((entry->day), day, 10);
					insertNode(list, entry); //Points a node to this data structure just created
				}
			}while (!feof(f));
			fclose(f);
			
			int length = 0;
			LinkedListNode *current = list->head;
			while (current != NULL){
				length++;
				current=current->next;//Counts the number of elements
			}
			Entry array[length];
			int x=0;
			
			current = list->head;
						while (current != NULL){
							array[x]=*((Entry*)(current->ptr));//Copies the data structure to the array
							LinkedListNode* temp = current;//Points temp to the current data structure node
							current=current->next;
							free(temp->ptr);//Frees the data structure holding the
							x++;
							}
			destroyList(list);
			if (strcmp(uoption,"name")==0){//Sends to name is the user option is "name"
				qsort(array,length,sizeof(Entry),&sortbyName);
			}
			else
			{
				qsort(array,length,sizeof(Entry),&sortbyTime);
			}
			
			outputFile(array, length, output);
			
		}

	
}

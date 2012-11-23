#include <stdlib.h>
#include "linked_list.h"

LinkedList *createList()
{
	LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
	list->head = NULL;//Sets head to null
	return list;
}

//This function was taken from the lecture slides
//Copyright David Cooper 2010
void destroyList(LinkedList* list)
{
	LinkedListNode* node;
	LinkedListNode* nextNode;
	
	node = list->head;
	while (node!=NULL){
		nextNode = node->next;
		free(node);
		node = nextNode;
	}
	
	free(list);
}
		
void insertNode(LinkedList* list, void* data)
{
	LinkedListNode *newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	newNode->ptr = data;//Points ptr to the entry
	newNode->next = list->head;
	list->head = newNode;
}
	

typedef struct LinkedListNode {
	void* ptr;
	struct LinkedListNode* next;//Points to next node
} LinkedListNode;

typedef struct {
	LinkedListNode* head;
} LinkedList;

LinkedList *createList();
void destroyList(LinkedList* list);
void insertNode(LinkedList* list,void* data);
	

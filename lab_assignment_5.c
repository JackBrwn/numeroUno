#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head){

	if(!head){
		printf("NULL pointer\n");
		return 0;
	}

	int len = 1;

	while(head -> next){
		len++;
		head = head -> next;
	}

	return len;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head){

	if(!head){
		printf("head is NULL\n");
		return "";
	}

	int len = length(head);

	char* string = (char*)malloc((len + 1) * sizeof(char));

	string[len] = '\0';

	for(int i = 0; i < len; i++){

		string[i] = head -> letter;
		head = head -> next;

	}

	return string;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c){

	node* newNode = (node*)malloc(1 * sizeof(node));
	newNode -> next = NULL;
	newNode -> letter = c;

	node* tmpNode = *pHead;

	if(!*pHead){
		*pHead = newNode;
		return;
	}

	while(tmpNode -> next)
		tmpNode = tmpNode -> next;

	tmpNode -> next = newNode;




	return;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead){

	if(!*pHead)
		return;

	int len = length(*pHead);

	for(int i = 0; i < len; i++)
		free(pHead[i]);

	pHead[0] = NULL;

	return;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}
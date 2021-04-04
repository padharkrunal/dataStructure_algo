#include <stdio.h>
#include <stdlib.h>

struct LLnode{
	int data;
	struct LLnode* next;
};
struct LLnode* getNode(int d){
	struct LLnode* newNode= (struct LLnode*) malloc(sizeof(struct LLnode));
	newNode->data=d;
	newNode->next=NULL;
	return newNode;
}
void PrintList(struct LLnode* head){
	struct LLnode* current=head;
	while(current!=NULL){
		printf("%d--->", current->data);
		current=current->next;
		}
		printf("\n");
}
void PrintListReverse(struct LLnode* head){
	if (!head)
//		printf("\n");
		return;
	PrintListReverse(head->next);
		printf("%d--->", head->data);
}
void InsertNode(struct LLnode** head, int data, int position){
	printf("Inserting node at %d position and value %d\n", position, data);
	struct LLnode* newNode, *current;
	current=*head;
	if ((*head==NULL) &&(position==1)){
		newNode= getNode(data);
		*head=newNode;
		}
	else if(position==1){
		newNode= getNode(data);
		newNode->next=current;
		*head=newNode;
	}
}
int main(){
	struct LLnode* head= NULL;
	InsertNode(&head, 30, 1);
	PrintList(head);
	PrintListReverse(head);
	InsertNode(&head, 20, 1);
	PrintList(head);
	PrintListReverse(head);
	InsertNode(&head, 10, 1);
	PrintList(head);
	PrintListReverse(head);
	return 0;
}

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
	if (!head){
		return;
	}
	
	PrintListReverse(head->next);
	printf("%d--->", head->data);
}
void InsertNode(struct LLnode** head, int data, int position){
	printf("Inserting node at %d position and value %d\n", position, data);
	struct LLnode* newNode, *current; //,*prev;
	int k=1;
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
	else{
		//prev=current;
		while((k<position-1) && (current->next!=NULL)){
			k++;
			//prev=current;
			current=current->next;
			}
		newNode= getNode(data);
		newNode->next=current->next;
		current->next=newNode;
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
	InsertNode(&head, 15, 2);
	PrintList(head);
	PrintListReverse(head);
	InsertNode(&head, 100, 5);
	PrintList(head);
	PrintListReverse(head);
	return 0;
}

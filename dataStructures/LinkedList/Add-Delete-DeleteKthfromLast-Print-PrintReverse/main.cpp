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
		printf("(%d)--->", current->data);
		current=current->next;
		}
		printf("\n");
}
void PrintListReverse(struct LLnode* head){
	if (!head){
		return;
	}
	
	PrintListReverse(head->next);
	printf("(%d)--->", head->data);
}
void InsertNode(struct LLnode** head, int data, int position){
	//printf("Inserting node at %d position and value %d\n", position, data);
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
void RemoveKthFromEnd(struct LLnode** head, int k){
	//int k=1;
	struct LLnode* p, *q, *npointer;
	if (*head==NULL){ // Empty List
		printf("Nothing to Delete\n");
		return;
	}
	if (k<1){
		printf("This Position cannot be deleted\n");
		return;
	}
	p = *head;
	npointer = p;
	while (k>0 && npointer!=NULL){
		npointer = npointer->next;
		k--;
	}
	if (npointer == NULL && k>0){
		printf("This Position does not Exist\n");
		return;
	} else if (npointer == NULL && k ==0){
		*head = (*head)->next;
		free(p);
	}else {
		while(npointer!= NULL){
			q=p;
			p=p->next;
			npointer= npointer->next;
		}
		q->next = p->next;
		free (p);
	}
	
	

}
void DeleteNode(struct LLnode** head, int data, int position){
	int k=1;
	struct LLnode* p, *q;
	if (*head==NULL){ // Empty List
		printf("Nothing to Delete\n");
		return;
	}
	p = *head;
	if (position ==1){ // Remove Head
		*head = (*head)->next;
		free (p);
		return;
		}
	else{
		while (p!=NULL && (k<position)){
			q = p;
			p = p->next;
			k++;
		}
		if (p == NULL) {
			printf("Position does not exist\n");
			return; 
		}else {
			q->next = p->next;
			free (p);
		}
	}

}
int main(){
	struct LLnode* head= NULL;
	//DeleteNode(&head, 100, 5);
	//PrintList(head);
	InsertNode(&head, 30, 1);
	//PrintList(head);
	//PrintListReverse(head);
	InsertNode(&head, 20, 1);
	//PrintList(head);
	//PrintListReverse(head);
	InsertNode(&head, 10, 1);
	//PrintList(head);
	//PrintListReverse(head);
	InsertNode(&head, 15, 2);
	//PrintList(head);
	//PrintListReverse(head);
	InsertNode(&head, 100, 5);
	PrintList(head);
	//PrintListReverse(head);
	RemoveKthFromEnd(&head, 3);	
	//DeleteNode(&head, 100, 1);
	PrintList(head);

	return 0;
}

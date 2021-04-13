#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct StackNode{
	int data;
	struct StackNode* next;
};
struct StackNode* newNode (int data){
	struct StackNode* stackNode = (struct StackNode *) malloc (sizeof(struct StackNode));
	stackNode->data=data;
	stackNode->next=NULL;
	return stackNode;
}
int isEmpty (struct StackNode *root){
	return !root;
}
void push (struct StackNode **root, int data){
	struct StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
	printf ("%d pushed to the stack \n",(*root)->data);
}
int pop (struct StackNode **root){
	if (isEmpty(*root))
		return INT_MIN;
	struct StackNode *temp=*root;
	*root=temp->next;
	int pop_data= temp->data;
	free(temp);
	return pop_data;
}
int peek(struct StackNode* root){
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}
void DeleteStack(struct StackNode **root){
	struct StackNode *temp, *p;
	p=*root;
	while(p){
		temp=p;
		p=p->next;
		printf("%d deleted\n",temp->data);
		free (temp);
	}
}


int main(){
	struct StackNode *root=NULL;
	push (&root,10);
	push (&root,20);
	push (&root,30);
	printf ("%d got popped \n", pop(&root));
	printf ("%d is at the top of the stack\n",peek(root));
	DeleteStack (&root);
	return 0;
}

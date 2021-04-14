#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue{
	int front, rear;
	unsigned capacity;
	int* array;
};
struct Queue * createQueue(unsigned size){
	struct Queue * queue= (struct Queue *) malloc(sizeof(struct Queue));
	if (!queue)
		return NULL;
	queue->capacity= size;
	queue->front=queue->rear=-1;
	queue->array = (int *)malloc (queue->capacity * sizeof(int));	
	return queue;
}
int isEmpty(struct Queue * queue){
	return (queue->front == -1);
}
int isFull (struct Queue * queue){
	return ((queue->rear+1) % queue->capacity == queue->front);	
}
int queueSize (struct Queue * queue){

}
void enqueue (struct Queue * queue, int item){
	if (isFull(queue))
		printf("Queue is Full\n");
	else {
		queue->rear=(queue->rear + 1) % queue->capacity;
		queue->array [queue->rear] = item;
		printf ("%d is enqueued at %d index\n", item, queue->rear);
		if (queue->front == -1)
			queue->front=queue->rear;

	}
}
int dequeue (struct Queue * queue){
	int item;
	if (isEmpty (queue)){
		printf ("Queue is Empty\n");
		return 0;
	}
	else {
		item = queue->array [queue->front];
		printf ("%d dequeued from index %d\n",item, queue->front);
		if (queue->front == queue->rear)
			queue->front=queue->rear=-1;
		else queue->front=(queue->front + 1) % queue->capacity;
		return item;

	}
}

void deleteQueue (struct Queue * queue){
	if (queue){
		if (queue->array)
			free (queue->array);
		free (queue);
		printf ("Queue us Deleted \n");
	}
}

int main(){
	struct Queue * queue= createQueue(8);
	enqueue (queue, 10);
	int data= dequeue (queue);
	enqueue (queue, 20);
	enqueue (queue, 45);
	data=dequeue (queue);
	deleteQueue (queue);
	return 0;
}

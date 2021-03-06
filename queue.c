#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void queue_init(queue_t* q){ //the queue does NOT go on the heap. thanks
	
	q->front = NULL;
	q->rear = NULL;
	q->count = 0;
}

q_node_t* q_node_init(void* data){
	if(data == NULL) {return NULL;} 

	q_node_t* qn = malloc(sizeof(q_node_t));

	qn->data = data;
	qn->next = NULL;
	qn->prev = NULL;

	return qn;
}

int isEmpty(queue_t* q){
	return !q->count; //1 if empty, 0 else
}


void enqueue(queue_t* q, q_node_t* qn){
	if(qn == NULL){return;}
	
	if(isEmpty(q)){
		q->front = qn;
		q->rear = qn;
		q->count++;
		return;
	}

	q_node_t* old_rear = q->rear;
	old_rear->next = qn;
	
	q->rear = qn;
	qn->prev = old_rear;
	qn->next = NULL;

	q->count++;
}

q_node_t* dequeue(queue_t* q){
	if(isEmpty(q)){return NULL;}

	q_node_t* head = q->front;
	
	if(head->next == NULL){
		q->front = NULL;
		q->rear = NULL;
		q->count = 0;
		return head;
	}

	q->front = q->front->next;
	q->front->prev = NULL;

	head->prev = NULL;
	head->next = NULL;

	q->count--;
	return head;
	
}

q_node_t* stack_dequeue(queue_t* q){
	if(isEmpty(q)){return NULL;}

	q_node_t* rear = q->rear;
	
	if(rear->prev == NULL){
		q->front = NULL;
		q->rear = NULL;
		q->count = 0;
		return rear;
	}
	
	q->rear = rear->prev; //reassign rear of queue
	q->rear->next = NULL;

	rear->prev = NULL; 
	return rear;

}

void free_queue(queue_t* q){
	while(!isEmpty(q)){
		q_node_t* qn = dequeue(q);
		free(qn);
	}
}

void print_queue(queue_t q){ //make a copy of queue
	while(!isEmpty(&q)){
		q_node_t* qn = dequeue(&q);
		printf("%d\n", *((int*) qn->data));
	}
}


/*
int main(){
	queue_t q;
	queue_init(&q);

	int a1 = 5;
	q_node_t* qn1 = q_node_init(&a1);

	int a2 = 7;
        q_node_t* qn2 = q_node_init(&a2);

	enqueue(&q, qn1);
	//print_queue(&q);

	dequeue(&q);
	//print_queue(&q);

	//free(qn1);

	queue_t q1;
	queue_init(&q1);
	
	enqueue(&q1, qn1);
	enqueue(&q1, qn2);
	print_queue(q1); //pass by value
	print_queue(q1);

	printf("-------%d\n", 9399);

	//stack_dequeue(&q1);
	
	print_queue(q1);

	printf("-------%d\n", 9399);

	print_queue(q1);
	
	free(qn1);
	free(qn2);
}
*/















#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

queue_t* queue_init(int len){
	queue_t* q = malloc(sizeof(node_t)*len); //create a queue of size len
	
	q->front = NULL;
	q->rear = NULL;
	q->count = 0;
	q->cap = len;

	return q;
}

q_node_t* q_node_init(void* data){
	q_node_t* qn = malloc(sizeof(q_node_t));

	qn->data = data;
	qn->next = NULL;
	qn->prev = NULL;

	return qn;
}

int isEmpty(queue_t* q){
	return !q->count; //1 if empty, 0 else
}

int isFull(queue_t* q){
	return q->count == q->cap;
}

void enqueue(queue_t* q, q_node_t* qn){
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

	q->front = q->front->next;
	q->front->prev = NULL;

	head->prev = NULL;
	head->next = NULL;

	q->count--;
	return head;
	
}
















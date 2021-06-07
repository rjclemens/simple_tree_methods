#ifndef CANDICE
#define CANDICE

#include "treetest.h"

typedef struct q_node{
	void* data; //can store any type (i.e. node_t)
	struct q_node* next;
	struct q_node* prev;

	int visited;
}q_node_t;

typedef struct queue{
	q_node_t* front;
	q_node_t* rear;

	int count;
	int cap; 
}queue_t;

q_node_t* q_node_init(void* data);
queue_t* queue_init(int len);

int isEmpty(queue_t* q);
int isFull(queue_t* q);

q_node_t* dequeue(queue_t* q);
void enqueue(queue_t* q, q_node_t* n);

#endif

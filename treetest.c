#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "treetest.h"
#include "queue.h"


void tree_init(tree_t* t1){
	t1->root = NULL;
	t1->count = 0;
}

node_t* node_init(int val){
	node_t* n1 = malloc(sizeof(node_t));
	
	n1->value = val;

	n1->leftNode = NULL;
	n1->rightNode = NULL;

	return n1;
}

void add(node_t* n, node_t** tn, tree_t* t){
	if(*tn == NULL){*tn = n; n->number = t->count++;}
	if(n->value < (*tn)->value){add(n, &((*tn)->leftNode), t);}
	else if(n->value > (*tn)->value){add(n, &((*tn)->rightNode), t);}
	else return;
}

void pop_random(node_t** tn, tree_t* t, int num){
	srand(time(0)); //set rand's seed to output varying number
	for(int i=0; i<num; i++){
		node_t* n = node_init(rand()%100);
		add(n, tn, t);
	}
}

void free_tree(node_t** tn){
	if(*tn == NULL){return; }

	free_tree(&((*tn)->leftNode));
	free_tree(&((*tn)->rightNode));

	free(*tn);

	return;
}


void print_tree(node_t* tn){ //inorder traversal
	if(tn == NULL){return;}
	print_tree(tn->leftNode);
	printf("print--%d\n", tn->value);
	print_tree(tn->rightNode);
}

void bfs(node_t* tn, int count){
	unsigned char* visited = calloc(count, sizeof(unsigned char)); //initialize array of all 0's

	queue_t qnp;
	queue_init(&qnp);

	queue_t* q = &qnp;
	
	q_node_t* tree_head = q_node_init(tn);
	enqueue(q, tree_head); //put root into queue

	while(!isEmpty(q)){
		q_node_t* dqd = dequeue(q);

		if(!visited[((node_t*) dqd->data)->number]){ //if NOT visited
			visited[((node_t*) dqd->data)->number] = 1; //mark node as visited

			//queue its children; cast void* to node_t*
			
			node_t* leftN = ((node_t*) dqd->data)->leftNode;
			node_t* rightN = ((node_t*) dqd->data)->rightNode;

			if(leftN != NULL){
				q_node_t* left = q_node_init(leftN);
				enqueue(q, left);
			}

			if(rightN != NULL){	
				q_node_t* right = q_node_init(rightN);
				enqueue(q, right);
			}


			//prints queue node's value in tree
			printf("bfs--%d\n", ((node_t*) dqd->data)->value);
		}
		
		free(dqd);
	}
	
	free(visited);
}

void dfs(node_t* tn, int count){
	unsigned char* visited = calloc(count, sizeof(unsigned char));

	queue_t stknp;
	queue_init(&stknp);
	

	queue_t* stk = &stknp;
	q_node_t* tree_head = q_node_init(tn);
	enqueue(stk, tree_head);

	while(!isEmpty(stk)){
		q_node_t* dqd = stack_dequeue(stk); //dequeue node from tail of queue (acts like stack)

		if(!visited[((node_t*) dqd->data)->number]){ //each entry of visited array corresponds to a node in tree
			visited[((node_t*) dqd->data)->number] = 1; //this entry has index node->number and is known for each node

			node_t* leftN = ((node_t*) dqd->data)->leftNode;
			node_t* rightN = ((node_t*) dqd->data)->rightNode;

			if(leftN != NULL){
				q_node_t* left = q_node_init(leftN);
				enqueue(stk, left);
			}

			if(rightN != NULL){
				q_node_t* right = q_node_init(rightN);
				enqueue(stk, right);
			}
			
			printf("dfs----%d\n", ((node_t*) dqd->data)->value);

		}

		free(dqd);
	}

	free(visited);
}


int main(){
	tree_t t2;
        tree_init(&t2);
	

	pop_random(&(t2.root), &t2, 35);

	print_tree(t2.root);

	printf("count------%d\n", t2.count);

	bfs(t2.root, t2.count);
	dfs(t2.root, t2.count);

	free_tree(&(t2.root));
}





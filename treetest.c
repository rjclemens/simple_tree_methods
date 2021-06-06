#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "treetest.h"


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

int add(node_t* n, node_t** tn){
	if(*tn == NULL){*tn = n; return 1;}
	if(n->value < (*tn)->value){return add(n, &((*tn)->leftNode));}
	else if (n->value > (*tn)->value){return add(n, &((*tn)->rightNode));}
	else{return 0;}
}

int pop_random(node_t** tn, int num){
	srand(time(0)); //set rand's seed to output varying number
	
	int added = 0;
	for(int i=0; i<num; i++){
		node_t* n = node_init(rand()%100);
		added += add(n, tn);
	}

	return added;
}

void free_tree(node_t** tn){
	if(*tn == NULL){return; }

	free_tree(&((*tn)->leftNode));
	free_tree(&((*tn)->rightNode));

	free(*tn);

	return;
}


void print_tree(node_t* tn){
	if(tn == NULL){return;}
	print_tree(tn->leftNode);
	printf("%d\n", tn->value); //inorder traversal
	print_tree(tn->rightNode);
}

int main(){
	tree_t t1;
	tree_init(&t1);
	
	tree_t t2;
	tree_init(&t2);

	node_t* n1 = node_init(5);

	node_t* n2 = node_init(7);
	

	t1.count += add(n1, &(t1.root));
	t1.count += add(n2, &(t1.root));

	print_tree(t1.root);
	

	free(n1);
	free(n2);



	t2.count = pop_random(&(t2.root), 15);
	print_tree(t2.root);
	printf("----------%d\n", t2.count);
	free_tree(&(t2.root));


}




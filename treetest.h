#ifndef PEN_ISLAND
#define PEN_ISLAND

typedef struct node{
        int value;
	int number;

        struct node* leftNode;
        struct node* rightNode;
} node_t;

typedef struct tree{
        struct node* root;
        int count;
} tree_t;

void add(node_t* n, node_t** tn, tree_t* t);
void print_tree(node_t* tn);
node_t* node_init(int val);
void tree_init(tree_t* t1);
void pop_random(node_t** tn, tree_t* t, int num);
void free_tree(node_t** tn);
void bfs(node_t* tn, int count);
void dfs(node_t* tn, int count);

#endif

#include <stdio.h>
#include <stdlib.h>

typedef struct s{
    int key;
    struct s* left;
    struct s* right;
}NODE;


NODE* creates_3_node_tree(){
    NODE* root = (NODE*) malloc(sizeof(NODE));
    NODE* left_node = (NODE*) malloc(sizeof(NODE));
    NODE* right_node = (NODE*) malloc(sizeof(NODE));

    root->key = 15;
    left_node->key = 10;
    right_node->key = 20;

    root->left = left_node;
    root->right = right_node;
    left_node->left = right_node->right = NULL;
    left_node->right = right_node->right = NULL;

    return root;
}


void post_order(NODE* p){
    if (!p) return;

    post_order(p->left);
    post_order(p->right);
    printf("Node : %d\n", p->key);

}


void destroy_tree(NODE* p){
    if (!p) return;

    destroy_tree(p->left);
    destroy_tree(p->right);

    printf("Node :%d being destroyed\n", p->key);
    NODE* aux = p;
    p = NULL;
    free(aux);
}

int height_of_node(NODE* p){

    if (!p) return 0;

    int l_h = height_of_node(p->left);
    int r_h = height_of_node(p->right);

    return (1+ (l_h > r_h ? l_h : r_h));
}

int main(){

    NODE* root = creates_3_node_tree();
    post_order(root);
    printf("The height of the tree is: %d\n", height_of_node(root));

    return 0;
}
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

void pre_order(NODE* p){
    /*
    The important concept about pre-order traversal is that 
    it processes the root before anything else, therefore
    it's useful when, for instance, copying a binary tree
    */
    if (!p){
        printf("Reached base case\n");
        return;
    }

    printf("Node key: %d\n", p->key);
    pre_order(p->left);
    pre_order(p->right);
}




int main(){

    NODE* root = creates_3_node_tree();
    pre_order(root);



    return 0;
}
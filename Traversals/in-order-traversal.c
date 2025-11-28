#include <stdio.h>
#include <stdlib.h>

/*
As the insertion and exclusion functions will be furthered
studied, I will manually create a 3-node tree just to study the
in-order traversal and copy-paste it for the pre-order and post-order*/


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


void in_order(NODE* p){
    if (!p) return;

    in_order(p->left);
    printf("%d\n", p->key);
    in_order(p->right);
}

void count_in_order(NODE* p, int i, int* call){
    *call = *call + 1;
    if (!p){
        return;
    }
    count_in_order(p->left, i+1, call);
    printf("Node-key : %d  reached in: %d - recursion call number: %d\n", p->key, i, *call);
    count_in_order(p->right, i+1, call);
}

void k_least_element(NODE* p, int k, int* count, int* result){
    if (!p) return;

    k_least_element(p->left, k, count, result);

    *count = *count + 1;

    if (*count == k){
        *result = p->key;
        return;
    }

    k_least_element(p->right, k, count, result);
}

int main(){

    NODE* root = creates_3_node_tree();
    in_order(root);
    int call = 1;
    count_in_order(root, 1, &call);
    int count = 0;
    int result;
    k_least_element(root, 1, &count, &result);
    printf("The first least element is: %d\n", result);
    


    return 0;
}
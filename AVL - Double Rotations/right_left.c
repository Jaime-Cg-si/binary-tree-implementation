#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s{

    struct s* left;
    struct s* right;
    int key;
    int height;

}NODE;

int get_height(NODE* p){
    if (!p) return 0;
    return p->height;
}

int max( int a, int b){
    if (a > b) return a;
    return b;
}

int update_height(NODE* p){

    if (!p) return 0;
    int left = update_height(p->left);
    int right = update_height(p->right);

    return 1 + max(left, right);
}

int get_balance_factor(NODE* p){

    if (!p) return 0;
    return get_height(p->right) - get_height(p->left);

}


NODE* left_left(NODE* unbalanced_node){

    NODE* rotation_node = unbalanced_node->left;
    NODE* right_subtree = rotation_node->right;

    rotation_node->right = unbalanced_node;
    unbalanced_node->left = right_subtree;

    update_height(unbalanced_node);
    update_height(rotation_node);
    return rotation_node;

}

NODE* right_right(NODE* unbalanced_node){

    NODE* rotation_node = unbalanced_node->right;
    NODE* left_subtree = rotation_node->left;

    rotation_node->left = unbalanced_node;
    unbalanced_node->right = left_subtree;

    update_height(unbalanced_node);
    update_height(rotation_node);

    return rotation_node;
}

NODE* left_right(NODE* unbalanced_node){

    NODE* x = unbalanced_node->left;

    NODE* rotated = right_right(x);
    unbalanced_node->left = rotated;
    
    return left_left(unbalanced_node);

}

NODE* right_left(NODE* unbalanced_node){

    NODE* x = unbalanced_node->right;
    NODE* rotated = left_left(x);
    unbalanced_node->right = rotated;

    return right_right(unbalanced_node);
}
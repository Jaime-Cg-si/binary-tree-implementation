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

int max (int a, int b){
    if (a >b) return a;
    return b;
}

int update_height(NODE* p){
    if (!p) return 0;

    int left = update_height(p->left);
    int right = update_height(p->right);

    return 1 + max(left, right);
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
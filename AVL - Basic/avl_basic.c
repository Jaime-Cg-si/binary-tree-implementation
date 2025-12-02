#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct s{
    struct s* left;
    struct s* right;
    int key;
    int height;
}NODE;

/*
Following the SRP (single responsability principle)
I will implement two different functions related to
the height value
*/

// This function simply treats the NULL case and returns the node height
int get_height(NODE* p){
    if (!p) return -1;
    return p->height;
}

//This function returns the biggest between 2 numbers
int max(int a, int b){
    if (a > b) return a;
    return b;
}

//This function updates the node height value
void update_height(NODE* p){

    int left_height = get_height(p->left);
    int right_height = get_height(p->right);

    p->height = 1+ max(left_height, right_height);
}

int get_balance_factor(NODE* p){

    if (!p) return 0;
    return get_height(p->right) - get_height(p->left);

}

bool is_avl(NODE* p){

    if (!p) return true;

    if (get_balance_factor(p) < -1 || get_balance_factor(p) > 1) return false;

    bool left_subtree = is_avl(p->left);
    if (!left_subtree) return false;
    
    return is_avl(p->right);
    
}

int tree_height(NODE* root){
    return get_height(root);
}

int count_nodes(NODE* p){

    if (!p) return 0;

    return 1 + count_nodes(p->left) + count_nodes(p->right);

}

int count_leaf(NODE* p){

    if (!p) return 0;

    if (!p->left && !p->right) return 1;

    return count_leaf(p->left) + count_leaf(p->right);

}
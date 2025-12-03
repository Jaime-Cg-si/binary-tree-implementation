#include <stdio.h>
#include <stdlib.h>

typedef struct s{
    int key;
    struct s* left;
    struct s* right;
}NODE;

int max(int a, int b){
    return (a > b ? a : b);
}


bool is_bst(NODE* p, int max, int min){

    if (!p) return true;

    if (p->key < min || p->key > max) return false;
    
    return (is_bst(p->left, p->key, min) && is_bst(p->right, min, p->key));


}
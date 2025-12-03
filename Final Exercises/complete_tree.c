#include <stdio.h>
#include <stdlib.h>

typedef struct s{
    int key;
    struct s* left;
    struct s* right;
}NODE;


bool is_complete(NODE* p){

    if (!p) return true;

    if (!p->right && !p->left) return true;

    if (!p->left || !p->right) return false;
    

    return (is_complete(p->left) && is_complete(p->right));
}
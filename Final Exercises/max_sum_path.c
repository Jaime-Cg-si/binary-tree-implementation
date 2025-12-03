#include <stdio.h>
#include <stdlib.h>

typedef struct s{
    int key;
    int height;
    struct s* left;
    struct s* right;
}NODE;

int max(int a, int b){
    return (a > b ? a : b);
}

int max_sum_path(NODE* p){

    if (!p) return 0;

    if (!p->left && !p->right) return p->key;

    return p->key + max(max_sum_path(p->left), max_sum_path(p->right));

}
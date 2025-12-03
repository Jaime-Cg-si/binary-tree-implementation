#include <stdio.h>
#include <stdlib.h>

typedef struct s{
    int key;
    int height;
    struct s* left;
    struct s* right;
}NODE;


int sum_even_keys(NODE* p){

    if (!p) return 0;

    if (p->key % 2 == 0){
        return p->key + sum_even_keys(p->left) + sum_even_keys(p->right);
    }
    return sum_even_keys(p->left) + sum_even_keys(p->right);

}
#include <stdio.h>
#include <stdlib.h>

typedef struct s{
    int key;
    struct s* left;
    struct s* right;
}NODE;


int print_ancestors(NODE* p, int value){

    if (!p) return 0;

    if (p->key == value) return 1;

    if (print_ancestors(p->left, value) || print_ancestors(p->right, value)){
        printf("%d\n", p->key);
        return 1;
    }

    

    return 0;
    

}
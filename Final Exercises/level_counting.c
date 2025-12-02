#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct s{
    int key;
    struct s* left;
    struct s* right;
}NODE;

/*
Find the number of levels in a tree
*/

int max(int a, int b){
    return (a > b ? a : b);
}

int level_count(NODE* p){

    if (!p) return 0;
    return 1 + max(level_count(p->left), level_count(p->right));

}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Implemente int contar_geracoes(NO* raiz) que retorna o número de gerações na árvore.
*/

typedef struct s{
    struct s* left;
    struct s* right;
    int key;
}NODE;

int level_count(NODE* p){
    if (!p) return 0;
    
    int left = level_count(p->left);
    int right = level_count(p->right);

    if (left > right) return 1 + left;
    else return 1 + right;
    
}
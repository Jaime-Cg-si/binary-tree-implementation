#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
The text from the problem will be in portuguese:
Implemente int somar_nos(NO* raiz) que retorna a soma de todas as chaves
*/

typedef struct s{
    struct s* left;
    struct s* right;
    int key;
}NODE;


int sum_all_nodes(NODE* p){

    if (!p) return 0;

    return p->key + sum_all_nodes(p->left) + sum_all_nodes(p->right);

}
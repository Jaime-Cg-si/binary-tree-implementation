#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
Implemente void listar_primos(NO* raiz, int nivel) 
que imprime todos os nós que estão no nível especificado.
*/

typedef struct s{
    struct s* left;
    struct s* right;
    int key;
}NODE;

void level_n_print(NODE* p, int n, int actual_level){
    if (!p) return;

    if (actual_level == n){
        printf("%d\n", p->key);
        return;
    }

    level_n_print(p->left, n, actual_level+1);
    level_n_print(p->right, n, actual_level+1);
}

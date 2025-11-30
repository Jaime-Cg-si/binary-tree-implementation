#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Implemente bool caminho_soma(NODE* p, int target) que retorna true 
se existe algum caminho raiz→folha cuja soma é igual a target
*/


typedef struct s{
    struct s* left;
    struct s* right;
    int key;
}NODE;

bool is_leaf(NODE* p){
    if (!p->left && !p->right) return true;
    return false;
}


bool sum_path(NODE* p, int target, int* sum, bool* ans){
    if (!p) return false;

    if (is_leaf(p) && p->key == target - *sum){
        *ans = true;
        return true;
    }
    else if (is_leaf(p) && p->key != target - *sum) return false;

    *sum = *sum + p->key;
    int actual = *sum;

    bool left = sum_path(p->left, target, sum, ans);

    if (!left){
        *sum = actual;
        bool right = sum_path(p->right, target, sum, ans);
    }
    return false;

}
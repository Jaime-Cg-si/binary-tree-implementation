#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct s{
    struct s* left;
    struct s* right;
    int key;
    int height;
}NODE;

int get_height(NODE* p){

    if (!p) return 0;
    return p->height;

}

int max(int a, int b){
    if (a > b) return a;
    return b;
}

int update_height(NODE* p){

    if (!p) return 0;

    int left = update_height(p->left);
    int right = update_height(p->right);

    return 1+ max(left, right);
}

int get_balance_factor(NODE* p){

    if (!p) return 0;
    return get_height(p->right) - get_height(p->left);
}

NODE* left_left_rotation(NODE* z){

    NODE* y = z->left;
    NODE* t2 = y->right;

    y->right = z;
    z->left = t2;

    update_height(z);
    update_height(y);

    return y;
}
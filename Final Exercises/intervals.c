#include <stdio.h>
#include <stdlib.h>

typedef struct s{
    int key;
    int height;
    struct s* left;
    struct s* right;
}NODE;




void search_node(NODE* root, int value, NODE** parent){

    *parent = NULL;
    NODE* p = root;

    while(p){

        if (p->key == value) return;

        *parent = p;

        if (p->key > value) p = p->left;

        else p = p->right;
    }
}

int count_subtree(NODE* p){

    if (!p) return 0;
    int left = count_subtree(p->left);
    int right = count_subtree(p->right);
    return 1 + left + right;
}

int greater_than_value(NODE* p, int value){
    if (!p) return 0;
    
    if (p->key > value){
       return 1 + greater_than_value(p->left, value) + greater_than_value(p->right, value);
    }
    
    return greater_than_value(p->left, value) + greater_than_value(p->right, value);
}
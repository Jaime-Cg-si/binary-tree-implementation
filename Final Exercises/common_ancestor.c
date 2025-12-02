#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




typedef struct s{

    struct s* left;
    struct s* right;
    int key;

}NODE;

void search_node(NODE* root, int value, NODE** parent){

    *parent = NULL;
    NODE* p = root;
    while (p){

        if (p->key == value) return;

        *parent = p;

        if (p->key > value) p = p->left;
        else p = p->right;
    }

}

NODE* common_ancestor(NODE* root, NODE* n1, NODE* n2){

    NODE* parent1;
    NODE* parent2;

    search_node(root, n1->key, &parent1);
    search_node(root, n2->key, &parent2);

    while(parent1){

        search_node(root, n2->key, &parent2);

        while(parent2){

            if (parent1 == parent2) return parent1;
            search_node(root, parent2->key, &parent2);

        }
        search_node(root, parent1->key, &parent1);
    }

    return root;
}



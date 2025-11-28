#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct s{
    struct s* left;
    struct s* right;
    int key;
}NODE;

bool search_node_x(NODE* p, int x, NODE** parent){

    *parent = NULL;

    while (p){

        if (p->key == x){
            return true;
        }

        *parent = p;

        if (p->key > x){
            p = p->left;
        }

        else {
            p = p->right;
        }

    }

    return false;

}

/*
The recursive search is another implementation
*/
void recursive_search(NODE* p, int x, NODE** parent, bool* found){

    if (!p) return;

    if (p->key == x){
        *found = true;
        return;
    }

    if (*found) return;

    if(!(*found)){

        if (p->left && p->key > x){
            *parent = p;
            printf("Searching Node : %d left son\n", p->key);
            recursive_search(p->left, x, parent, found);
        }
        else if (p->right && p->key < x){
            *parent = p;
            printf("Searching Node : %d right son\n", p->key);
            recursive_search(p->right, x, parent, found);
        }
    }
}


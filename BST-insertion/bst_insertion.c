#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
I shall re-implement the bst-search
alg. in order to study it further, and then
I will implement the insertion alg.
*/

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

        if (x < p->key){
            p = p->left;
        }

        else{
            p = p->right;
        }


    }

    return false;

}

void insertion(NODE** root, int value){

    NODE* parent;

    if (search_node_x(*root, value, &parent)){
        printf("The value %d already exists!\n", value);
        return;
    }

    else{
        NODE* new_node = (NODE*) malloc(sizeof(NODE));
        new_node->key = value;
        new_node->left = new_node->right = NULL;

        if (!parent){
            *root = new_node;
            printf("Node : %d inserted at the root!\n", value);
            return;
        }
        else{
            if (value < parent->key){
                parent->left = new_node;
                printf("Node %d added left from Node %d\n", value, parent->key);
                return;
            }

            else {
                parent->right = new_node;
                printf("Node %d added right from Node %d\n", value, parent->key);
                return;
            }
        }

    }

}

void recursive_insertion(NODE** root, NODE* p, int x, NODE** parent){

    if (!p){
        NODE* new_node = (NODE*) malloc(sizeof(NODE));
        new_node->key = x;
        new_node->left = new_node->right = NULL;

        if (! (*parent)){
            *root = new_node;
            return;
        }
        else{

            if ((*parent)->key > x){
                (*parent)->left = new_node;
            }
            else{
                (*parent)->right = new_node;
            }
            return;
        }
    }

    if (p->key == x){
        printf("Value already in the tree\n");
        return;
    }

    else{
        *parent = p;
        if (x < p->key){
            recursive_insertion(root, p->left, x, parent);
        }
        else{
            recursive_insertion(root, p->right, x, parent);
        }
    }

}


int main(){


    NODE* root = NULL;
    insertion(&root, 10);
    insertion(&root, 15);
    insertion(&root, 5);

    return 0;
}
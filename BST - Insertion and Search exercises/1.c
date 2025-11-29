#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Implemente NODE* construir_abb(int valores[], int n)
que recebe um array e retorna uma ABB com todos os valores
*/


typedef struct s{
    struct s* left;
    struct s* right;
    int key;
}NODE;

void insertion(NODE* root, int value);
bool search(NODE* p, int value, NODE** parent);
void receive_array(int* v, int size);
NODE* create_bst(int* v);

int main(){

    int size;
    printf("How many nodes do you wish to insert: ");
    scanf("%d", &size);
    printf("\n");
    int array[size];
    receive_array(array, size);

    return 0;
}

void receive_array(int* v, int size){

    for (int i = 0; i < size; i++){
        printf("Insert the element: \n");
        scanf("%d", &v[i]);
    }

}

bool search(NODE* p, int value, NODE** parent){

    *parent = NULL;

    while(p){

        if (p->key == value){
            return true;
        }

        *parent = p;

        if (value < p->key){
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
    if (search(*root, value, &parent)) return;

    NODE* new_node = (NODE*) malloc(sizeof(NODE));
    new_node->key = value;
    new_node->left = new_node->right = NULL;

    if (!(*parent)){
        *root = new_node;
        return;
    }
    else{
        if ((*parent)->key >value){
            (*parent)->left = new_node;
        }
        else{
            (*parent)->right = new_node;
        }
        return;
    }
}

NODE* create_bst(int* v, int size){
    NODE* root = NULL;

    for (int i = 0; i < size; i++){
        insertion(&root, v[i]);
    }
    return root;
}
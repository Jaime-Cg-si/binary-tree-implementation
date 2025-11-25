#include <stdio.h>
#include <stdlib.h>


typedef struct s{
    int key;
    struct s* left;
    struct s* right;
    /*each pointer has 8 bytes*/
}NODE;


void func_x(NODE* p){
    printf("p adress : %p\n", &p);
    printf("p points to: %p\n", p);
    printf("making p point to null...\n");
    p = NULL;
    printf("p now points to : %p\n", p);
}

void deletes_node(NODE** q){
    printf("q adress : %p\n", &q);
    printf("q points to : %p\n", q);
    free(*q);
    *q = NULL;
}

int main(){

    NODE* root = (NODE*) malloc(sizeof(NODE));
    printf("Root adress : %p\n", &root);
    printf("Root points to: %p\n", root);
    func_x(root);
    printf("Root still points to : %p\n", root);
    deletes_node(&root);
    printf("Root points to: %p\n", root);



    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct s{

    int key;
    struct s* left;
    struct s* right;

}NODE;

typedef struct t{
    struct t* next;
    NODE* tree_node;
}QUEUE_NODE;

typedef struct{
    QUEUE_NODE* start;
    QUEUE_NODE* end;
}QUEUE;


void queue_traversal(NODE* root, QUEUE* q);

QUEUE* ini_queue();

void insert_node_queue(QUEUE* q, NODE* node);

NODE* remove_node_queue(QUEUE* q);

bool empty_queue(QUEUE* q);

NODE* creates_3_node_tree();

int main(){

    QUEUE* q = ini_queue();
    NODE* root = creates_3_node_tree();
    queue_traversal(root, q);

    return 0;
}

QUEUE* ini_queue(){

    QUEUE* q = (QUEUE*) malloc(sizeof(QUEUE));
    q->start = q->end = NULL;
    return q;
}

void insert_node_queue(QUEUE* q, NODE* node){
    if (!node) return;

    QUEUE_NODE* new_element = (QUEUE_NODE*) malloc(sizeof(QUEUE_NODE));
    new_element->tree_node = node;
    new_element->next = NULL;

    if (q->start == NULL){
        //printf("Node  : %d inserted at the beginning of the queue\n", node->key);
        q->start = q->end = new_element;
        return;
    }

    //printf("Node  : %d inserted at the end of the line\n", node->key);
    q->end->next = new_element;
    q->end = new_element;
}

NODE* remove_node_queue(QUEUE* q){

    if (!q) return NULL;
    QUEUE_NODE* aux = q->start;
    q->start = aux->next;

    NODE* answer = aux->tree_node;
    free(aux);

    if (q->start == NULL){
        q->end = NULL;
    }

    return answer;
}

bool empty_queue(QUEUE* q){
    if (q->start == NULL) return true;
    return false;
}

void queue_traversal(NODE* root, QUEUE* q){
    insert_node_queue(q, root);

    while(!empty_queue(q)){
        NODE* node = remove_node_queue(q);
        printf("Node key: %d\n", node->key);
        insert_node_queue(q, node->left);
        insert_node_queue(q, node->right);
    }
}

NODE* creates_3_node_tree(){
    NODE* root = (NODE*) malloc(sizeof(NODE));
    NODE* left_node = (NODE*) malloc(sizeof(NODE));
    NODE* right_node = (NODE*) malloc(sizeof(NODE));

    root->key = 15;
    left_node->key = 10;
    right_node->key = 20;

    root->left = left_node;
    root->right = right_node;
    left_node->left = right_node->right = NULL;
    left_node->right = right_node->right = NULL;

    return root;
}
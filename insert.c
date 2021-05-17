#include "insert.h"
#include <stdio.h>
#include <stdlib.h>

//bst
struct tNode *BST_insert(struct tNode *T, int key){
    if(T == NULL){
        struct tNode *p = (struct tNode *) malloc(sizeof(struct tNode));
        p->key = key;
        p->Lchild = NULL;
        p->Rchild = NULL;
        return p; 
    }
    if(T->key >= key){
        T->Lchild = BST_insert(T->Lchild, key);
    }
    else{
        T->Rchild = BST_insert(T->Rchild, key);
    }
    return T;
}

//bs
int compare(const void *a, const void *b){
    int c = *(int *) a;
    int d = *(int *) b;
    if(c < d) return -1;
    else if(c == d) return 0;
    else return 1;
}

void BS_insert(int *insert_data, int N){
    qsort(insert_data, N, sizeof(int), compare);
}

//arr
void ARR_insert(int *arr, int *insert_data, int N){
    int i;
    for(i=0;i<N;i++){
        arr[i] = insert_data[i];
    }
}

//ll
struct lnode *LL_insert(struct lnode *L, int key){
    struct lnode *p = (struct lnode *) malloc(sizeof(struct lnode));
    p->key = key;
    p->next = L;
    return p;
}

//hash_ll
void init(int N){
    int i;
    for(i = 0; i < N; i++){
        chain[i] = NULL;
    }
}

void Hashll_insert(int key, int size){
    struct dNode *newNode = malloc(sizeof(struct dNode));
    newNode->key = key;
    newNode->next = NULL;

    int idx = key % size;

    if(chain[idx] == NULL){
        chain[idx] = newNode;
    }    
    else
    {
        struct dNode *temp = chain[idx];
        while(temp->next)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//hash
void Hash_insert(int key, int size){
    struct dNode2 *new_item = (struct dNode2*) malloc(sizeof(struct dNode2));
    new_item->key = key;

    int idx = key % size;

    while(arr[idx].item != NULL){
        ++idx;
        idx %= size;
    }
    arr[idx].item = new_item;
}
#include "insert.h"
#include "search.h"
#include <stdio.h>

//bst
struct tNode *BST_search(struct tNode *T, int key){
    if(T == NULL) return NULL;
    int c = T->key - key;
    if(c==0) return T;
    else if(c>0) return BST_search(T->Lchild, key);
    else return BST_search(T->Rchild, key);
}

//bs
int BS_search(int *insert_data, int search, int N){
    int mid,head=0,tail=N;
    while(head <= tail){
        mid = (head + tail) / 2;
        if(insert_data[mid] == search){
            return mid;
        }
        else if(insert_data[mid] < search){
            head = mid + 1;
        }
        else{
            tail = mid - 1;
        }
    }
    return -1;
}

//arr
int ARR_search(int *insert_data, int search, int N){
    int i;
    for(i=0;i<N;i++){
        if(insert_data[i] == search){
            return i;
        }
    }
    return -1;
}

//ll
struct lnode *LL_search(struct lnode *L, int key){
    struct lnode *p = L;
    while(p){
        if(p->key == key){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

//hash_ll
int Hashll_search(int key, int size){
    int idx = key % size;
    if(chain[idx] == NULL){
        return -1;
    }
    else{
        struct dNode *temp = chain[idx];
        while(temp){
            if(temp->key == key){
                return idx;
            }
            temp = temp->next;
        }
        return -1;
    }
}

//hash
struct dNode2 *Hash_search(int key, int size){
    int idx = key % size;

    while(arr[idx].item != NULL){
        if(arr[idx].item->key == key){
            return arr[idx].item;
        }
        ++idx;
        idx %= size;
    }
    return NULL;
}
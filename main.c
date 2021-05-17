#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "insert.h"
#include "search.h"
#include "test_data.h"
#define TEST_DATA_CNT 1000000
#define ON 1
#define OFF 0

int *test_data;

int main(int argc, char **argv){
    int i,N,p,M;
    int BST=OFF,BS=OFF,ARR=OFF,LL=OFF,HASH=OFF;
    int *insert_data, *search_data;

    test_data = (int *) malloc(sizeof(int)*TEST_DATA_CNT);    
    insert_data = (int *) malloc(sizeof(int)*TEST_DATA_CNT);
    search_data = (int *) malloc(sizeof(int)*TEST_DATA_CNT);

    for(i=1;i<argc;i++){
        if(strcmp(argv[i],"-d")==0){
            i++;
            if((argv[i][0] == '1') && (argv[i][1] == 'e')){
                p = argv[i][2] - '0';
                N = pow(10,p);
            }
            else{
                N = atoi(argv[i]);
            }
        }
        else if(strcmp(argv[i],"-q")==0){
            i++;
            if((argv[i][0] == '1') && (argv[i][1] == 'e')){
                p = argv[i][2] - '0';
                M = pow(10,p);
            }
            else{
                M = atoi(argv[i]);
            }
        }
        else if(strcmp(argv[i],"-bst")==0){
            BST = ON;
        }
        else if(strcmp(argv[i],"-bs")==0){
            BS = ON;
        }
        else if(strcmp(argv[i],"-arr")==0){
            ARR = ON;
        }
        else if(strcmp(argv[i],"-ll")==0){
            LL = ON;
        }
        else if(strcmp(argv[i],"-hash")==0){
            HASH = ON;
        }
    }

    generate_test_data(test_data, N);

    struct rusage start_usage;
    struct rusage end_usage;
    struct timeval start;
    struct timeval end;
    unsigned long diff;
    long int diff_usage;

    if(BST == ON){
        printf("\nBinary Search Tree:\n");
        for(i=0;i<N;i++){
            insert_data[i] = test_data[i];
        }

        getrusage(RUSAGE_SELF, &start_usage);
        gettimeofday(&start, NULL);
        struct tNode *T = NULL;
        for(i=0;i<N;i++){
            T = BST_insert(T, insert_data[i]);
        }
        gettimeofday(&end, NULL);
        diff = 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
        printf("buliding time: %f sec\n",diff/1000000.0);

        gettimeofday(&start, NULL);
        srand(2);
        for(i=0;i<M;i++){
            search_data[i] = rand();
            BST_search(T, search_data[i]);
        }
        gettimeofday(&end, NULL);
        getrusage(RUSAGE_SELF, &end_usage);
        diff = 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
        printf("query time: %f sec\n",diff/1000000.0);
        diff_usage = end_usage.ru_maxrss - start_usage.ru_maxrss;
        printf("Memory usage: %ld KB\n",diff_usage);
    }
    if(BS == ON){
        printf("\nArray with Binary Search:\n");
        for(i=0;i<N;i++){
            insert_data[i] = test_data[i];
        }

        getrusage(RUSAGE_SELF, &start_usage);
        gettimeofday(&start, NULL);
        BS_insert(insert_data, N);
        gettimeofday(&end, NULL);
        diff = 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
        printf("buliding time: %f sec\n",diff/1000000.0);

        gettimeofday(&start, NULL);
        srand(2);
        for(i=0;i<M;i++){
            search_data[i] = rand();
            BS_search(insert_data, search_data[i], N);
        }
        gettimeofday(&end, NULL);
        getrusage(RUSAGE_SELF, &end_usage);
        diff = 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
        printf("query time: %f sec\n",diff/1000000.0);
        diff_usage = end_usage.ru_maxrss - start_usage.ru_maxrss;
        printf("Memory usage: %ld KB\n",diff_usage);
    }
    if(ARR == ON){
        printf("\nArray:\n");
        for(i=0;i<N;i++){
            insert_data[i] = test_data[i];
        }

        getrusage(RUSAGE_SELF, &start_usage);
        gettimeofday(&start, NULL);
        int *arr = (int*) malloc(sizeof(int)*N);
        ARR_insert(arr ,insert_data, N);
        gettimeofday(&end, NULL);
        diff = 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
        printf("buliding time: %f sec\n",diff/1000000.0);

        gettimeofday(&start, NULL);
        srand(2);
        for(i=0;i<M;i++){
            search_data[i] = rand();
            ARR_search(arr, search_data[i], N);
        }
        free(arr);
        gettimeofday(&end, NULL);
        getrusage(RUSAGE_SELF, &end_usage);
        diff = 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
        printf("query time: %f sec\n",diff/1000000.0);
        diff_usage = end_usage.ru_maxrss - start_usage.ru_maxrss;
        printf("Memory usage: %ld KB\n",diff_usage);
    }
    if(LL == ON){
        printf("\nLinked list:\n");
        for(i=0;i<N;i++){
            insert_data[i] = test_data[i];
        }

        getrusage(RUSAGE_SELF, &start_usage);
        gettimeofday(&start, NULL);
        struct lnode *keyList = NULL;
        for(i=0;i<N;i++){
            keyList = LL_insert(keyList, insert_data[i]);
        }
        gettimeofday(&end, NULL);
        diff = 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
        printf("buliding time: %f sec\n",diff/1000000.0);

        gettimeofday(&start, NULL);
        srand(2);
        for(i=0;i<M;i++){
            search_data[i] = rand();
            LL_search(keyList, search_data[i]);
        }
        gettimeofday(&end, NULL);
        getrusage(RUSAGE_SELF, &end_usage);
        diff = 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
        printf("query time: %f sec\n",diff/1000000.0);
        diff_usage = end_usage.ru_maxrss - start_usage.ru_maxrss;
        printf("Memory usage: %ld KB\n",diff_usage);
    }
    if(HASH == ON){
        printf("\nhash_ll:\n");
        for(i=0;i<N;i++){
            insert_data[i] = test_data[i];
        }

        getrusage(RUSAGE_SELF, &start_usage);
        gettimeofday(&start, NULL);
        init(N);
        for(i=0;i<N;i++){
            Hashll_insert(insert_data[i], N);
        }
        gettimeofday(&end, NULL);
        diff = 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
        printf("buliding time: %f sec\n",diff/1000000.0);

        gettimeofday(&start, NULL);
        srand(2);
        for(i=0;i<M;i++){
            search_data[i] = rand();
            Hashll_search(search_data[i], N);
        }
        gettimeofday(&end, NULL);
        getrusage(RUSAGE_SELF, &end_usage);
        diff = 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
        printf("query time: %f sec\n",diff/1000000.0);
        diff_usage = end_usage.ru_maxrss - start_usage.ru_maxrss;
        printf("Memory usage: %ld KB\n",diff_usage);

        printf("\nhash:\n");
        for(i=0;i<N;i++){
            insert_data[i] = test_data[i];
        }
        getrusage(RUSAGE_SELF, &start_usage);
        gettimeofday(&start, NULL);
        arr = (struct hashtable*) malloc(sizeof(struct hashtable)*2*N);
        for(i=0;i<2*N;i++){
            arr[i].item = NULL;
        }
        for(i=0;i<N;i++){
            Hash_insert(insert_data[i], 2*N);
        }
        gettimeofday(&end, NULL);
        diff = 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
        printf("buliding time: %f sec\n",diff/1000000.0);

        gettimeofday(&start, NULL);
        srand(2);
        for(i=0;i<M;i++){
            search_data[i] = rand();
            Hash_search(search_data[i], 2*N);
        }
        gettimeofday(&end, NULL);
        getrusage(RUSAGE_SELF, &end_usage);
        diff = 1000000*(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
        printf("query time: %f sec\n",diff/1000000.0);
        diff_usage = end_usage.ru_maxrss - start_usage.ru_maxrss;
        printf("Memory usage: %ld KB\n",diff_usage);
    }

    free(test_data);
    free(insert_data);
    free(search_data);
    return 0;
}
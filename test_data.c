#include "test_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_test_data(int *test_data, int N){
    int i,j,t;
    srand(time(NULL));
    for(i=0;i<N;i++){
        test_data[i] = i + 1;
    }
    for(i=0;i<N;i++){
        j = rand() % (N - i) + i;
        t = test_data[i];
        test_data[i] = test_data[j];
        test_data[j] = t;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEMENTS 10

int list[MAX_ELEMENTS] = {1, 130, 142, 143, 144, 145, 146, 148, 149, 150};
int count;

init_list(){
    int i;
    strand(1);
    for(i=0; i<MAX_ELEMENTS; i++){
        list[i] = i;
    }
}

int search_interpolation(int key, int n){
    int low, high, j;
    low = 0;
    high = n-1;

    while((list[high] >= key) && (key > list[low])){
        j = ((float)(key - list[low]) / (list[high]) * (high - low)) + low;
        if (key > list[j]) low = j + 1;
        else if (key < list[j]) high = j - 1;
        else low = j;
    }
    if (list[low] == key) return(low);
    else return -1;
}


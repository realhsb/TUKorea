#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )

int list[MAX_SIZE+1];
int n;

// 순차 탐색 (sequential search)
int seq_search(int key, int low, int high){
    int i;
    for(i = low; i <= high; i++)
        if(list[i]==key)
            return i;   // 탐색 성공
    return -1;          // 탐색 실패
}

int seq_search2(int key, int low, int high){
    int i;
    list[high + 1] = key;
    for(i = low; list[i] != key; i++){
        ;
    }
    if(i==(high+1)) {
        return -1;  // 탐색 실패
    } else{
         return i;      // 탐색 성공
    }
}

int main(void){
    int i, result;
    clock_t start, end;

    n = MAX_SIZE;

    srand(1);
    for(i = 0; i < n; i++){
        list[i] = rand() % 100;
    }

    for(i = 0; i < n; i++){
        printf("%d ", list[i]);
    }

    result = seq_search2(7, 0, n-1);    // key, low, high

    if(result == -1){
        printf("\n- 탐색 실패(%d)\n", result);
    }else {
        printf("-탐색 성공(%d)\n", result);
    }

    return 0;
}
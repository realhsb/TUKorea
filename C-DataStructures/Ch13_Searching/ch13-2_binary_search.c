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

// recursive binary search
int search_binary(int key, int low, int high){
    int middle;
    if(low <= high){
        middle = (low + high) / 2;
        if(key == list[middle]) {
            return middle;
        }else if(key < list[middle]){
            return search_binary(key, low, middle -1);
        }
    }
    return -1;
}


int search_binary2(int key, int low, int high){
    int middle;
    while(low <= high) {                                     // 아직 숫자가 남아있으면
        middle = (low+high)/2;                            // 탐색 성공
        if(key == list[middle]) return middle;      // 왼쪽 부분리스트 탐색
        else if(key > list[middle]) low = middle + 1;   // 오른쪽 부분리스트 탐색
        else    high = middle - 1; // key < list[middle] 
    }
    return -1;      // 탐색 실패
}
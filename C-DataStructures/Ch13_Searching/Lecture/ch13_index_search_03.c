#include <stdio.h>

#define MAX_SIZE    9
#define INDEX_SIZE  3

int list[MAX_SIZE] = { 3, 9, 15, 22, 31, 55, 67, 88, 91 };
int n = 9;

typedef struct {
    int     key;
    int     index;
} itable;

itable index_list[INDEX_SIZE] = { {3,0}, {22,3}, {67,6} };

//
int seq_search(int key, int low, int high)
{
    int i;

    for (i = low; i < high; i++) {
        if (list[i] == key) {
            return i;   // 탐색에 성공하면 키 값의 인덱스 반환
        }
    }

    return -1;          // 탐색에 실패하면 -1 반환
}

// INDEX_SIZE는 인덱스 테이블의 크기,n은 전체 데이터의 수
int index_search(int key)
{
    int i, low = 0, high = n-1;

    // 키 값이 리스트 범위 내의 값이 아니면 탐색 종료
    if (key < list[0] || key > list[n - 1]) {
        return -1;
    }

    // itable index_list[INDEX_SIZE] = { {3,0}, {15,3}, {67,6} };  //(key, index)
    // 인덱스 테이블을 조사하여 해당키의 구간 결정
    for (i = 0; i < INDEX_SIZE; i++) {
        if (index_list[i].key <= key && index_list[i + 1].key > key) {
            low     = index_list[i].index;
            high    = index_list[i + 1].index;
            break;
        }else if (index_list[i].key <= key && index_list[i + 1].key == 0) {
            low     = index_list[i].index;
            high    = n;
            break;
        }
    }

    // 예상되는 범위만 순차 탐색
    return seq_search(key, low, high);
}

//
void main()
{
    int i;
    i = index_search(17);

    if (i >= 0) {
        printf("> 탐색 성공 i = %d\n", i);
    }
    else {
        printf("> 탐색 실패\n");
    }
}



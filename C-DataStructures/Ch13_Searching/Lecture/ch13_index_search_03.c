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
            return i;   // Ž���� �����ϸ� Ű ���� �ε��� ��ȯ
        }
    }

    return -1;          // Ž���� �����ϸ� -1 ��ȯ
}

// INDEX_SIZE�� �ε��� ���̺��� ũ��,n�� ��ü �������� ��
int index_search(int key)
{
    int i, low = 0, high = n-1;

    // Ű ���� ����Ʈ ���� ���� ���� �ƴϸ� Ž�� ����
    if (key < list[0] || key > list[n - 1]) {
        return -1;
    }

    // itable index_list[INDEX_SIZE] = { {3,0}, {15,3}, {67,6} };  //(key, index)
    // �ε��� ���̺��� �����Ͽ� �ش�Ű�� ���� ����
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

    // ����Ǵ� ������ ���� Ž��
    return seq_search(key, low, high);
}

//
void main()
{
    int i;
    i = index_search(17);

    if (i >= 0) {
        printf("> Ž�� ���� i = %d\n", i);
    }
    else {
        printf("> Ž�� ����\n");
    }
}



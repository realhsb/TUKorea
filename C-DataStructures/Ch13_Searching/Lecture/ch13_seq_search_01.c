#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE+1];
int n;

//
int seq_search(int key, int low, int high)
{
	int i;

	for (i = low; i <= high; i++) {
		if (list[i] == key) {
			return i;	// Ž���� �����ϸ� Ű ���� �ε��� ��ȯ 
		}
	}
	return -1;			// Ž���� �����ϸ� -1 ��ȯ 
}

// �� Ƚ���� ���̵��� �ڵ� ����.
int seq_search2(int key, int low, int high)
{
	int i;
	list[high + 1] = key;  		// Ű ���� ã���� ����  
	for (i = low; list[i] != key; i++) {
		;
	}
	if (i == (high + 1)) {
		return i;  			// Ž�� ���� 
	}else {
		return i;          		// Ž�� ���� 
	}
}

//
int main(void)
{
	int i, result;
	clock_t start, end;

	n = MAX_SIZE;
	//srand(time(NULL));
	srand(1);
	for (i = 0; i < n; i++) {     	// ���� ���� �� ��� 
		list[i] = rand() % 100;	
	}
	
	for (i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}

	result = seq_search2(-1, 0, n - 1);
	
	if (result == -1) {
		printf("\n- Ž�� ����(%d)\n", result);
	}
	else {
		printf("- Ž�� ����(%d)\n", result);
	}
	
	return 0;
}


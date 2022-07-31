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
			return i;	// 탐색에 성공하면 키 값의 인덱스 반환 
		}
	}
	return -1;			// 탐색에 실패하면 -1 반환 
}

// 비교 횟수를 줄이도록 코드 변경.
int seq_search2(int key, int low, int high)
{
	int i;
	list[high + 1] = key;  		// 키 값을 찾으면 종료  
	for (i = low; list[i] != key; i++) {
		;
	}
	if (i == (high + 1)) {
		return i;  			// 탐색 실패 
	}else {
		return i;          		// 탐색 성공 
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
	for (i = 0; i < n; i++) {     	// 난수 생성 및 출력 
		list[i] = rand() % 100;	
	}
	
	for (i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}

	result = seq_search2(-1, 0, n - 1);
	
	if (result == -1) {
		printf("\n- 탐색 실패(%d)\n", result);
	}
	else {
		printf("- 탐색 성공(%d)\n", result);
	}
	
	return 0;
}


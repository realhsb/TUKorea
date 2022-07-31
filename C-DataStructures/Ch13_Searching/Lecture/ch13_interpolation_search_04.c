#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEMENTS 10
//int list[MAX_ELEMENTS] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//int list[MAX_ELEMENTS] = { 1, 30, 80, 120, 130, 135, 146, 148, 149, 150 };
int list[MAX_ELEMENTS] = { 1, 130, 142, 143, 144, 145, 146, 148, 149, 150 };
int count;	// 수행횟수
//
init_list()
{
	int i;
	srand(1);
	for (i = 0; i < MAX_ELEMENTS; i++) {
		list[i] = i;
	}
}
// recursive binary search...
int search_binary(int key, int low, int high)
{
	int middle;
	if (low <= high) {
		middle = (low + high) / 2;
		if (key == list[middle]) {		// 탐색 성공
			return middle;
		}else if (key < list[middle]) {	// 왼쪽 부분리스트 탐색 
			return search_binary(key, low, middle - 1);
		}else {							// 오른쪽 부분리스트 탐색 
			return search_binary(key, middle + 1, high);
		}
	}
	return -1;        // 탐색 실패
}
// iterative binary search...
int search_binary2(int key, int n)
{
	int		low, high;
	low		= 0;
	high	= n - 1;
	int		middle;

	while (low <= high) {       // 아직 숫자들이 남아 있으면
		middle = (low + high) / 2;

		if (key == list[middle]) {
			return middle;
		}else if (key > list[middle]) {
			low = middle + 1;
		}else {
			high = middle - 1;
		}
	}
	return -1;   // 발견되지 않음 
}
//
int search_interpolation(int key, int n)
{
	int		low, high, j;
	low		= 0;
	high	= n - 1;

	while ((list[high] >= key) && (key > list[low])) {
		j = ((float)(key - list[low]) / (list[high] - list[low]) * 
			(high - low)) + low;
		
		if (key > list[j]) {
			low = j + 1;
		}else if (key < list[j]) {
			high = j - 1;
		}else {
			low = j;
		}
	}
	if (list[low] == key) {
		return(low);	//found(r[low])
	}else {
		return -1;		// notfound(key)
	}
}
//
void main()
{
	int i = 0, search_number;
	
	printf("> 데이터: ");
	for (i = 0; i < MAX_ELEMENTS; i++) {
		printf(" %d", list[i]);
	}
	printf("\n");

	printf("> 탐색할 숫자를 입력하시요 : ");
	scanf("%d", &search_number);

	count = 0;
	i = search_binary2(search_number, MAX_ELEMENTS);
	
	if (i >= 0) {
		printf("탐색 성공 i = %d\n", i);
	}else {
		printf("탐색 실패\n");
	}

	count = 0;
	i = search_interpolation(search_number, MAX_ELEMENTS);
	
	if (i >= 0) {
		printf("탐색 성공 i = %d\n", i);
	}else {
		printf("탐색 실패\n");
	}
}

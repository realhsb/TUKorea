#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define		MAX_QUEUE_SIZE		100
#define		BUCKETS				10
#define		DIGITS				4
#define		SIZE				10
#define		MAX_SIZE			10

int list[MAX_SIZE];
int n;

typedef int element;
typedef struct { // ť Ÿ��
	element		data[MAX_QUEUE_SIZE];
	int			front, rear;
} QueueType;

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ���� ���� ���� �Լ�
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

//
void radix_sort(int list[], int n)
{
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];

	// ť���� �ʱ�ȭ
	for (b = 0; b < BUCKETS; b++) {
		init_queue(&queues[b]);  
	}

	for (d = 0; d < DIGITS; d++) {
		
		// �����͵��� �ڸ����� ���� ť�� ����
		for (i = 0; i < n; i++) {
			enqueue(&queues[(list[i] / factor) % 10], list[i]);
		}

		// ��Ŷ���� ������ list�� ��ģ��.
		for (b = i = 0; b < BUCKETS; b++) {
			while (!is_empty(&queues[b])) {
				list[i++] = dequeue(&queues[b]);
			}
		}

		// �� ���� �ڸ����� ����.
		factor *= 10;
	}
}

//
int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i < n; i++) {     	// ���� ���� �� ��� 
		list[i] = rand() % 100;		// ���� �߻� ���� 0~99
	}

	radix_sort(list, n);
	for (i = 0; i < n; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
	return 0;
}


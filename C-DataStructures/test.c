#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

typedef struct ListNode {
   struct ListNode* link;
   char ID;
   char name;
   float grade;
   int rank;
} ListNode;

ListNode* insert_first(ListNode* head, char ID, char name, float grade)           //insert_first함수 정의
{
   ListNode *p = (ListNode *)malloc(sizeof(ListNode));       //ListNode만큼의 크기를 할당하는 포인터 변수 선언
   ID = (char)malloc(sizeof(char) * strlen(ID));
   strcpy(p->ID, ID);
   strcpy(p->name, name);
   p->grade = grade;
   p->link = head;                                           //link에 헤드 포인터의 값 복사
   head = p;                                               // 헤드 포인터 변경
   return head;                                           // 변경된 헤드 포인터 반환
}

ListNode* delete_first(ListNode* head)      //delete_first함수 정의
{
   ListNode* removed;                      //구조체 ListNode의 헤드주소를 가리키는 포인터변수  선언
   if (head == NULL) return NULL;          //헤드포인터가 비어있다면 NULL을 리턴
   removed = head;                           //지울 노드에 head주소 할당
   head = removed->link;                   //원래 있던 head에 removed의 다음 주소를 할당
   free(removed);                          //removed 할당했던거 풀어주기
   return head;                          //변경된 헤드포인터 반환
}

void print_list(ListNode* head)                         //print_list함수 정의
{
   FILE* fp;
   //ListNode* p = (ListNode*)malloc(sizeof(ListNode));
   int i = 1;
   fp = fopen("04.txt", "a+");
   for (ListNode* p = head; head != NULL; p = p->link) {
      fprintf(fp, "%d %s %s %f %d\n", i, p[i].ID, p[i].name, p[i].grade, p[i].rank);
      i++;
   }
}

void insertion_sort(float list[], int n)
{
    int i, j;
   float key;
    for (i = 1; i < n; i++) {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--)
            list[j + 1] = list[j]; /* 레코드의 오른쪽 이동 */
        list[j + 1] = key;
    }
}

int main() {
    ListNode* a;
   float grade[5];
   char insertID;
   int j;
   

    a = malloc(5 * sizeof(ListNode));
    if (a == 0) {
        printf("메모리가 비어있습니다.");
        return 1;
    }
   ListNode* head = (ListNode*)malloc(sizeof(ListNode));
   insert_first(head, "2020131055", "ojm", 3.82);
   insert_first(head, "2020131011", "sjm", 3.99);
   insert_first(head, "2020132044", "ajm", 4.3);
   insert_first(head, "2020132033", "yjm", 4.2);
   insert_first(head, "2020132022", "bjm", 4.25);

   for (int i = 1; i < 6; i++) {
      grade[i] = a[i].grade;
   }

   insertion_sort(grade, 6);

   for (int i = 1; i < 6; i++) {
      for (int j = 1; j < 6; j++) {
         if (a[i].grade == grade[j]) a[i].rank = j;
      }
   }

   print_list(a);
   printf("학번을 입력하시오.");
   scanf("%s", &insertID);
   for (int i = 1; i < 6; i++) {
      if (strcmp(a[i].ID, &insertID)) {
         j = i;
      }
      else if(strcmp(&insertID, "q")) {
         return 0;
      }
   }

   printf("학점 : %f, 등수 : %d\n", a[j].grade, a[j].rank);

    free(a);
}
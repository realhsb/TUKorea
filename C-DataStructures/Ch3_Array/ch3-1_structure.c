#include <stdio.h>

typedef struct studentTag{
    char name[10];
    int age;
    double gpa;
} student;

int main(void){
    student a = {"kim", 20, 4.3};
    student b = {"park", 21, 4.1};
    return 0;
}
#include <stdio.h>
#include <time.h>
#define DATA_SIZE 10000
#define LOOP_CNT 10000
int main(void){
    int data[DATA_SIZE];
    double result = 0.0;
    clock_t start, end;
    double duration;

    //data 배열 값 초기화
    for(int i = 0; i < DATA_SIZE; i++){
        data[i] = i + 1;
    }

    // 실행 속도 측정 시작
    printf("> 측정 시작.\n");
    start = clock();    //msec
    for(int j = 0; j < LOOP_CNT; j++){
        for(int i = 0; i < DATA_SIZE; i++){
            result += (double) data[i];
        }
    }
    end = clock();
    printf("> 측정 완료.\n");
    // 속도 측정 완료
    duration =(double) (end - start)  / CLOCKS_PER_SEC;

    printf("> 실행 시간 = %1f  sec\n", duration);
    printf("> CLOCKS_PER_SEC : %d\n",  CLOCKS_PER_SEC);
}

// #include <stdio.h>
// #include <time.h>
// #define DATA_SIZE 10000
// #define LOOP_CNT 10000
// int main(void){
//     int data[DATA_SIZE];
//     double result = 0.0;
//     time_t start, end;
//     double duration;

//     //data 배열 값 초기화
//     for(int i = 0; i < DATA_SIZE; i++){
//         data[i] = i + 1;
//     }

//     // 실행 속도 측정 시작
//     printf("> 측정 시작.\n");
//     start = time(NULL);   //msec
//     for(int j = 0; j < LOOP_CNT; j++){
//         for(int i = 0; i < DATA_SIZE; i++){
//             result += (double) data[i];
//         }
//     }
//     end = time(NULL);
//     printf("> 측정 완료.\n");
//     // 속도 측정 완료
//     duration =(double) (end - start);

//     printf("> 실행 시간 = %1f  sec\n", duration);
//     printf("> CLOCKS_PER_SEC : %d\n",  CLOCKS_PER_SEC);
// }
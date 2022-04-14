#include <iostream>
using namespace std;

int big(int a, int b){
    if(a>b) return a;
    else return b;
}
int big(int a[], int size){
    int res = a[0];
    for(int i = 0; i < size, i++){
        if(res < a[i]) res = a[i];
    }
}
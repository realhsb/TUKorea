//[예제 4-6] 정수형 배열의 동적 할당 및 반환
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "정수를 입력하시오 : " ;
    cin >> n;
    int *p = new int[n];

    if(!p){
        cout << "메모리 할당 불가";
        return 0;
    }
    for(int i = 0; i < n; i++){
        cout<< i+1<< "번째 정수 : ";
        cin >> p[i];
    }
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += p[i];
    }
    cout << "평균 : " << sum / n << endl;
    delete [] p;
}
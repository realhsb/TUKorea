#include <iostream>
using namespace std;

template <class T>
T biggest (T x[], int n){
    if(n == 0){
        return 0;
    }else {
        T max = x[0];
         for(int i = 1; i < n; i++){
             if(max < x[i]) max = x[i];
        }
        return max;
    }
}

int main(){
    int x[] = {1, 10, 100, 5, 4};
    cout << biggest(x, 5) << endl;
    double y[] = {6.4, 3.3, -200.6, 7.7, 8.8, 20.3};
    cout << biggest(y, 6) << endl;
}
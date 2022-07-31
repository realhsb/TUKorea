//
#include <iostream>
using namespace std;
template <class T>
class MyStack {
    int tos;        // top of stack
    T data[100];
public :
    MyStack();
    void push(T  element);
    T pop();
};
template <class T>
MyStack<T>::MyStack(){      // 생성자
    tos = -1;
}
template <class T>
void MyStack<T>::push(T element) {
    if(tos == 99){
        cout << "stack full"; return;
    }
    tos++; data[tos] = element;
}
template <class T>
T MyStack<T> ::pop(){
    T retData;
    if(tos == -1){
        cout << "stack empty"; return 0;
    }
    retData = data[tos--];
    return retData;
}
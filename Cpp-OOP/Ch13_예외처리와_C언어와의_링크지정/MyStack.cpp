#include "MyStack.h"
void MyStack::push(int n) throw(char*){
    if(tos == 99)
        throw "Stack Full";
    tos++;  data[tos] = n;
}

int MyStack::pop() throw(char*) {
    if(tos == -1)
        throw "Stack Empty";
    int rData = data[tos--];
    return rData;
}
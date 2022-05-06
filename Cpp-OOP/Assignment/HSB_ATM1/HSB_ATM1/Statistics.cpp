#include "Statistics.h"

int Statistics::sum(Account * pArray, int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        if(pArray[i].getAcctID() > 0){
            sum += pArray[i].getBalance();
        }
    }
    return sum;
}

int Statistics::average(Account * pArray, int size){
    int count = 0;
    int sum = 0;
    if(size <= 0){
        return 0;
    }
    for (int i = 0; i < size; i++){
        if(pArray[i].getAcctID() > 0){
            count++;
            sum += pArray[i].getBalance();
        }
    }
    return sum / count;
}

int Statistics::max(Account * pArray, int size){
    int max = 0;
    for(int i = 0; i < size; i++){
        if(pArray[i].getAcctID() > 0 && pArray[i].getBalance() > max){
            max = pArray[i].getBalance();
            break;
        }
    }
    return max;
}

void Statistics::sort(Account* pArray, int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - 1 - i; j++){
            if (pArray[j].getBalance() < pArray[j + 1].getBalance()){
                Account temp = pArray[j];
                pArray[j] = pArray[j + 1];
                pArray[j + 1] = temp;
            }
        }
    }
}

#ifndef STATISTICS_H
#define STATISTICS_H

#include <stdio.h>
#include "Account.h"

class Statistics {
public:
    static int sum(Account * pArray, int size); // 계좌 잔고 총합
    static int average(Account * pArray, int size); // 계좌 잔고 평균
    static int max(Account * pArray, int size);
    static void sort(Account* pArray, int size);
};


#endif 

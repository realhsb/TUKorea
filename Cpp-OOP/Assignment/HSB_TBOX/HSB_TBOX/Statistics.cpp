#include "Statistics.h"

int Statistics:: totalRevenue(Screen* pScreen){
    int total = 0;
    Ticket** t = pScreen->getTicketArray();
    for(int i = 0; i < pScreen->getRowMax(); i++){
        for(int j = 0; j < pScreen->getColMax(); j++){
            if(t[i][j].getCheck()==SEAT_COMPLETION_MARK){
                total += t[i][j].getPayAmount();
            }
        }
    }
    return total;
}

int Statistics:: totalSalesCount(Screen* pScreen){
    int count = 0;
    Ticket** t = pScreen->getTicketArray();
    for(int i = 0; i < pScreen->getRowMax(); i++){
        for(int j = 0; j < pScreen->getColMax(); j++){
            if(t[i][j].getCheck()==SEAT_COMPLETION_MARK){
                count++;
            }
        }
    }
    return count;
}

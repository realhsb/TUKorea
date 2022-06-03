#include "Statistics.h"

int Statistics:: totalRevenue(Screen* pScreen){
    int total = 0;
    int row = pScreen->getRowMax(); int col = pScreen->getColMax();
    Ticket** ticketArray = pScreen->getTicketArray();
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(ticketArray[i][j].getCheck()==SEAT_COMPLETION_MARK){
                total += ticketArray[i][j].getPayAmount();
            }
        }
    }
    return total;
}

int Statistics:: totalSalesCount(Screen* pScreen){
    int count = 0;
    int row = pScreen->getRowMax(); int col = pScreen->getColMax();
    Ticket** ticketArray = pScreen->getTicketArray();
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(ticketArray[i][j].getCheck()==SEAT_COMPLETION_MARK){
                count++;
            }
        }
    }
    return count;
}

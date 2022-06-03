#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include "Ticket.h"

using namespace std;



class Screen {
protected :
    int nTicketPrice;       // 티켓 가격
    int nRowMax, nColMax;   // 좌석 행과 열 최대 값
    int nCurrentReservedId; // 발급된 마지막 예약 번호
    Ticket** pSeatArray;    // 스크린 좌석에 대한 티켓 배열
    string strMovieName;    // 스크린 상영 중인 영화 제목
public :
    Screen(string name, int price, int row, int col);
    ~Screen();
    void showSeatMap();                 // 좌석 예약 여부 맵으로 보기
    virtual void showMovieMenu();       // 영화 예매 메뉴
    virtual void showMovieInfo() = 0;   // 영화 소개 정보
    
    void reserveTicket();               // 추가 기능 1 : 좌석 예약하기
    
    Ticket* checkReservedID(int id);    // 추가 기능 2 : 예약 번호 확인
    void cancelReservation();           // 추가 기능 2 : 좌석 예약 취소하기
    
    int getTicketPrice(){return nTicketPrice;} // 추가 기능 3
    void Payment();                     // 추가 기능 3 : 티켓 결제
    
    int getRowMax() {return nRowMax;}   // 추가 기능 4
    int getColMax() {return nColMax;}
    Ticket** getTicketArray(){return pSeatArray;}
};

class EuropeScreen : public Screen {
public :
    EuropeScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
     void showMovieInfo();
};

class AsiaScreen : public Screen {
public :
    AsiaScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
     void showMovieInfo();
};

class PremiumScreen : public Screen {
public :
    PremiumScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
     void showMovieInfo();
};

#endif

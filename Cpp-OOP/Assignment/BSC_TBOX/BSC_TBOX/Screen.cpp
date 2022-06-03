#include <iostream>
#include <string>
#include "Screen.h"
#include "Pay.h"

using namespace std;

Screen::Screen(string name, int price, int row, int col) {
    strMovieName = name;
    nRowMax = row;
    nColMax = col;
    nTicketPrice = price;
    pSeatArray = new Ticket*[nRowMax];
    for (int r = 0; r < nRowMax; r++){
        pSeatArray[r] = new Ticket[nColMax];
    }
    for (int i = 0; i < nColMax; i++){
        for(int j = 0; j < nRowMax; j++){
            pSeatArray[i][j].setCheck(SEAT_EMPTY_MARK);
        }
    }
    nCurrentReservedId = 100;
}

// 2. 좌석 예약 현황
void Screen::showSeatMap(){
    cout << "  [좌석 예약 현황]" << endl;
    
    for(int i = -1; i < nRowMax; i++){
        for(int j = -1; j < nColMax; j++){
            if(i == -1){
                if(j == -1) cout << "\t";
                else if(j == nColMax - 1) continue;
                cout << "[" << j+2 << "] ";
            }else {
                if(j == -1)
                    cout << "[" << i+1 << "] ";
                else
                    cout << "[" << pSeatArray[i][j].getCheck() << "] ";
            }
        }
        cout << endl;
    }
}

// 1. 상영 영화 정보
void Screen::showMovieMenu(){
    cout <<"----------------------------------------\n";
    cout << "  영화 메뉴 - " << strMovieName;
    cout << "\n----------------------------------------\n";
    cout << "1. 상영 영화 정보\n";
    cout << "2. 좌석 예약 현황\n";
    cout << "3. 예약 하기\n";
    cout << "4. 예약 취소\n";
    cout << "5. 결제 하기\n";
    cout << "7. 메인 메뉴 이동\n" << endl;
}

void EuropeScreen::showMovieInfo(){
    cout << "  영화관 : 유럽영화 1관\n" <<
            "  주인공 : 오웬 윌슨, 레이첼 맥 아담스\n" <<
            "  줄거리 : 약혼자 이네즈를 두고 홀로 파리의 밤거리를 배회하던 길은 ...\n" <<
            "  가격 : " << nTicketPrice << endl;
}

void AsiaScreen::showMovieInfo(){
    cout << "  영화관 : 아시아영화 2관\n" <<
            "  주인공 : 박지민, 김석진\n" <<
            "  줄거리 : 지민이와 석진이는 골프 치러 가는 길에 수빈이를 만나고야 마는데 ...\n" <<
            "  가격 : " << nTicketPrice << endl;
}

void PremiumScreen::showMovieInfo(){
    cout << "  영화관 : 프리미엄영화 3관\n" <<
            "  주인공 : 정호석, 김남준, 민윤기\n" <<
            "  줄거리 : 개노답 3형제는 방탄소년단이 아닌 방탄청년단이 되겠다고 선언하는데 ...\n" <<
            "  가격 : " << nTicketPrice << endl;
}

void Screen::reserveTicket(){
    int row = 0; int col = 0;
    bool check = false;
    cout << "  [ 좌석 예약 ]" << endl;
    cout << "좌석 행 번호 입력 (1-" << nRowMax << ") : ";
    cin >> row;
    cout << "좌석 열 번호 입력 (1-" << nColMax << ") : ";
    cin >> col;
    cout << endl;
    
    for(int r = 0; r < nRowMax; r++){
        for(int c = 0; c < nColMax; c++){
            if(r == row-1 && c == col-1){
                if(pSeatArray[r][c].getCheck() == SEAT_EMPTY_MARK) {
                    check = true;
                    
                    pSeatArray[r][c].setCheck(SEAT_RESERVED_MARK);
                    pSeatArray[r][c].setSeat(row, col);
                    pSeatArray[r][c].setReservedID(nCurrentReservedId);

                    cout << "행[" << row << "] 열[" << col << "] " << nCurrentReservedId << "예약 번호로 접수되었습니다." << endl;
                    nCurrentReservedId++;
                }
                break;
            }
        }
    }
    if(!check){
        cout << "존재하지 않는 좌석입니다" << endl;
    }
}

Ticket* Screen::checkReservedID(int id){
    for(int r = 0; r < this->nRowMax; r++){
        for(int c = 0; c < this->nColMax; c++){
            if(this->pSeatArray[r][c].getReservedID() == id && this->pSeatArray[r][c].getCheck() == SEAT_RESERVED_MARK){
                return &pSeatArray[r][c];
            }
        }
    }
    return NULL;
}

void Screen::cancelReservation(){
    int res = 0;
    
    cout << "  [좌석 예약 취소]";
    cout << "예약 번호 입력 : ";
    cin >> res;
    
    Ticket* res_ticket;
    
    if((res_ticket = checkReservedID(res)) != NULL){
        res_ticket->setSeat(-100, -100);
        res_ticket->setReservedID(-100);
        res_ticket->setCheck(SEAT_EMPTY_MARK);
        
        cout << res << " 예약 번호가 취소 처리되었습니다." << endl;
    }else {
        cout << "예약 취소 불가능" << endl;
    }
}

void Screen::Payment(){
    int res = 0;
    int num = 0;
    Ticket* res_ticket = NULL;
    
    cout << " [좌석 예약 결제]";
    cout << "예약 번호 입력 : ";
    cin >> res;
    
    res_ticket = checkReservedID(res);
    
    if(res_ticket == NULL){
        cout << "존재하지 않는 예약입니다." << endl;
        return;
    }
    
    cout << "----------------------------------------\n";
    cout << "\t결제 방식 선택";
    cout << "\n----------------------------------------\n";
    cout << "1. 모바일 결제\n";
    cout << "2. 은행 이체 결제\n";
    cout << "3. 카드 결제\n";
    cout << "결제 방식 (1~3)" << endl;
    cin >> num;
    
    if(num == MOBILE_PHONE_PAYMENT){
        cout << "  [모바일 결제]" << endl;
        string phone_num = "";
        string name = "";
        
        // 티켓 결제 방법 등록
        res_ticket->setPayMethod(MOBILE_PHONE_PAYMENT);
        Pay* pay = new MobilePay(MOBILE_PHONE_INTEREST_RATE);
        
        cout << "핸드폰 번호 입력(12자리 수) : ";
        cin >> phone_num;
        cout << "이름: ";
        cin >> name;
        cout << endl;
        
        // 티켓 결제 금액 입력
        int price = pay->charge(getTicketPrice());
        res_ticket->setPayAmount(price);
        
        cout << "모바일 결제가 완료되었습니다. : " << res_ticket->getPayAmount() << endl;
        res_ticket->setCheck(SEAT_COMPLETION_MARK);
    }else if(num == BANK_TRANSFER_PAYMENT){
        cout << "  [KPU 은행 결제]" << endl;
        string account_num = "";
        string name = "";
        
        // 티켓 결제 방법 등록
        Pay* pay = new BankTransfer(BANK_TRANSFER_INTEREST_RATE);
        res_ticket->setPayMethod(BANK_TRANSFER_PAYMENT);
        
        cout << "은행 번호 입력(12자리 수) : ";
        cin >> account_num;
        cout << "이름: ";
        cin >> name;
        
        // 티켓 결제 금액 입력
        int price = pay->charge(getTicketPrice());
        res_ticket->setPayAmount(price);
        
        cout << " KPU 은행 결제가 완료되었습니다. : " << res_ticket->getPayAmount() << endl;
        res_ticket->setCheck(SEAT_COMPLETION_MARK);
    }else if(num == CREDIT_CARD_PAYMENT){
        cout << "  [신용카드 결제]" << endl;
        string credit_num = "";
        string name = "";
        
        // 티켓 결제 방법 등록
        Pay* card_pay = new CardPay(CREDIT_CARD_INTEREST_RATE);
        res_ticket->setPayMethod(CREDIT_CARD_PAYMENT);
        
        cout << "카드 번호 입력(12자리 수): ";
        cin >> credit_num;
        cout << "이름: ";
        cin >> name;
        
        // 티켓 결제 금액 입력
        int price = card_pay->charge(getTicketPrice());
        res_ticket->setPayAmount(price);
        
        cout << " 신용카드 결제가 완료되었습니다. : " << res_ticket->getPayAmount() << endl;
        res_ticket->setCheck(SEAT_COMPLETION_MARK);
    }else {
        cout << "잘못 입력했습니다." << endl;
    }
}

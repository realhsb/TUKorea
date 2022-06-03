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
    cout << "\t[ 좌석 예약 현황 ]" << endl;
    
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
    cout <<
    "----------------------------------------\n" <<
    "\t영화 메뉴 - " << strMovieName <<
    "\n----------------------------------------\n" <<
    "1. 상영 영화 정보\n2. 좌석 예약 현황\n3. 예약 하기\n4. 예약 취소\n5. 결제 하기\n7. 메인 메뉴 이동\n" << endl;
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
    cout << "\t[ 좌석 예약 ]" << endl;
    cout << "좌석 행 번호 입력 (1 - " << nRowMax << ") : ";
    cin >> row;
    cout << "좌석 열 번호 입력 (1 - " << nColMax << ") : ";
    cin >> col;
    cout << endl;
    
    for(int i = 0; i < nRowMax; i++){
        for(int j = 0; j < nColMax; j++){
            if(i == row-1 && j == col-1){
                if(pSeatArray[i][j].getCheck() == SEAT_EMPTY_MARK) {
                    check = true;
                    
                    pSeatArray[i][j].setCheck(SEAT_RESERVED_MARK);
                    pSeatArray[i][j].setSeat(row, col);
                    pSeatArray[i][j].setReservedID(nCurrentReservedId);
//                    Ticket ticket = pSeatArray[i][j];
//                    ticket.setCheck(SEAT_RESERVED_MARK);
//                    ticket.setSeat(row, col);
//                    ticket.setReservedID(100);
                    cout << "행[" << row << "] 열[" << col << "] " << nCurrentReservedId << "예약 번호로 접수되었습니다." << endl;
                    nCurrentReservedId++;
                }else {
                    cout << "이미 예약되거나 결제된 좌석입니다." << endl;
                }
                break;
            }
        }
    }
    if(!check){
        cout << "존재하지 않는 좌석 번호입니다." << endl;
    }
}

Ticket* Screen::checkReservedID(int id){
    Ticket* ticket = NULL;
    
    for(int i = 0; i < nRowMax; i++){
        for(int j = 0; j < nColMax; j++){
            if(pSeatArray[i][j].getReservedID() == id && pSeatArray[i][j].getCheck() == SEAT_RESERVED_MARK){
                ticket = &pSeatArray[i][j];
                break;
            }
        }
    }
    return ticket;
}

void Screen::cancelReservation(){
    int id = 0;
    Ticket* ticket = NULL;
    
    cout << "\t[좌석 예약 취소]";
    cout << "예약 번호 입력 : ";
    cin >> id;
    
    ticket = this->checkReservedID(id);
    
    if(ticket == NULL){
        cout << "예약을 취소할 수 없습니다." << endl;
    }else {
        ticket->setCheck(SEAT_EMPTY_MARK);
        ticket->setReservedID(-1);
        ticket->setSeat(-1, -1);
        cout << id << " 예약 번호가 취소 처리되었습니다." << endl;
    }
}

void Screen::Payment(){
    int id = 0;
    int num = 0;
    Ticket* ticket = NULL;
    
    cout << "\t[좌석 예약 결제]";
    cout << "예약 번호 입력 : ";
    cin >> id;
    
    ticket = this->checkReservedID(id);
    
    if(ticket == NULL){
        cout << "예약을 결제할 수 없습니다." << endl;
        return;
    }
    
    cout <<
    "----------------------------------------\n" <<
    "\t결제 방식 선택" <<
    "\n----------------------------------------\n" <<
    "1. 모바일 결제\n2. 은행 이체 결제\n3. 카드 결제\n" <<
    "결제 방식 (1~3)" << endl;
    cin >> num;
    
    Pay* pay = NULL;
    int amount = 0;
    string pay_num;
    string name;
    
    switch(num){
        case CREDIT_CARD_PAYMENT : {
            
            cout << "\t[신용카드 결제]" << endl;
            
            // 티켓 결제 방법 등록
            ticket->setPayMethod(CREDIT_CARD_PAYMENT);
            pay = new CardPay(CREDIT_CARD_INTEREST_RATE);
            
            
            cout << "카드 번호 입력(12자리 수) : ";
            cin >> pay_num;
            cout << endl;
            cout << "이름 : ";
            cin >> name;
            cout << endl;
            
            // 티켓 결제 금액 입력
            amount = pay->charge(this->getTicketPrice());
            ticket->setPayAmount(amount);
            
            cout << " 신용카드 결제가 완료되었습니다. : " << ticket->getPayAmount() << endl;
            break;
        }
            
        case BANK_TRANSFER_PAYMENT : {
            
            cout << "\t[KPU 은행 결제]" << endl;
            
            // 티켓 결제 방법 등록
            ticket->setPayMethod(BANK_TRANSFER_PAYMENT);
            pay = new BankTransfer(BANK_TRANSFER_INTEREST_RATE);
            
            
            cout << "은행 번호 입력(12자리 수) : ";
            cin >> pay_num;
            cout << endl;
            cout << "이름 : ";
            cin >> name;
            cout << endl;
            
            // 티켓 결제 금액 입력
            amount = pay->charge(this->getTicketPrice());
            ticket->setPayAmount(amount);
            
            cout << " KPU 은행 결제가 완료되었습니다. : " << ticket->getPayAmount() << endl;
            break;
        }
            
        case MOBILE_PHONE_PAYMENT : {
            
            cout << "\t[모바일 결제]" << endl;
            
            // 티켓 결제 방법 등록
            ticket->setPayMethod(MOBILE_PHONE_PAYMENT);
            pay = new CardPay(MOBILE_PHONE_INTEREST_RATE);
            
            
            cout << "핸드폰 번호 입력(12자리 수) : ";
            cin >> pay_num;
            cout << endl;
            cout << "이름 : ";
            cin >> name;
            cout << endl;
            
            // 티켓 결제 금액 입력
            amount = pay->charge(this->getTicketPrice());
            ticket->setPayAmount(amount);
            
            cout << "모바일 결제가 완료되었습니다. : " << ticket->getPayAmount() << endl;
            break;
        }
        default :
            break;
    };
    
    
    ticket->setCheck(SEAT_COMPLETION_MARK);
}

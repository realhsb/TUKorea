#include <iostream>
#include "Screen.h"
#include "TicketBox.h"
#include "Statistics.h"
#include <string>
using namespace std;

// 스크린 객체 생성
void TUKoreaTBox::Initialize(){
    //Screen(영화제목, 티켓가격, 좌석(nRowMax), 좌석(nColMax))
    pEuropeScreen = new EuropeScreen("미드나잇 인 파리", 10000, 10, 10);
    pAsiaScreen = new AsiaScreen("무간도3 - 종극무간", 12000, 10, 10);
    pPremiumScreen = new PremiumScreen("에너미 앳 더 게이트", 30000, 6, 6);
}

TUKoreaTBox::TUKoreaTBox(){}

TUKoreaTBox::~TUKoreaTBox(){}

Screen* TUKoreaTBox::selectMenu(){
    int num = 0;
    cout << "1.\t유럽\t영화 1관\n" <<
            "2.\t아시아\t영화 2관\n" <<
            "3.\t프리미엄\t영화 3관\n" <<
            "9.\t 통계\t관리\n" <<
            "선택(1~3, 9) 그 외 종료 : ";
    cin >> num;
    cout << endl;
    switch(num){
        case 1 :
            return pEuropeScreen;
        case 2 :
            return pAsiaScreen;
        case 3 :
            return pPremiumScreen;
        case 9 :
            this->Manage();
            return NULL;
        default:
            return NULL;
    }
}

void TUKoreaTBox:: Manage(){
    string pwd = "";
    cout << "비밀번호를 입력하세요. : ";
    cin >> pwd;

    while(true){
        if(pwd.compare(TICKET_BOX_MANAGER_PWD) == 0){
            int EuropeRevenue = Statistics::totalRevenue(pEuropeScreen);
            int AsiaRevenue = Statistics::totalRevenue(pAsiaScreen);
            int PremiumRevenue = Statistics::totalRevenue(pPremiumScreen);
            
            int totalSales = Statistics::totalSalesCount(pEuropeScreen) + Statistics::totalSalesCount(pAsiaScreen) + Statistics::totalSalesCount(pPremiumScreen);
            
            cout << "1. 유럽영화 상영관 결제금액 : " << EuropeRevenue << endl;
            cout << "2. 아시아영화 상영관 결제금액 : " << AsiaRevenue << endl;
            cout << "3. 프리미엄영화 상영관 결제금액 : " << PremiumRevenue << endl;

            cout << "4. 전체 티켓 판매량 : " << totalSales << endl;
            break;
        }else {
            cout << "비밀번호가 일치하지 않습니다. \n비밀번호를 다시 입력하세요. : ";
            cin >> pwd;
        }
    }
}

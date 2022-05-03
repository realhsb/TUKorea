#ifndef ATMACHINE_H
#define ATMACHINE_H
#include "Account.h"

using std::string;

#define NEGATIVE_ATM_BALANCE        -10

class ATMachine {
    private :
        Account *pAcctArray;                //동적 생성된 고객계좌 배열 포인터
        int nMachineBalance;                //ATM 잔고
        int nMaxAccountNum;              //동적 생성된 고객계좌 배열 크기
        int currentAccountNum;           //개설된 고객 계좌 수
        string strManagerPassword;      //관리자 비밀번호

    public :
        ATMachine (int size, int balance, string password);
        ~ATMachine();

        void displayMenu();                 //ATM
        void createAccount();               //계좌 개설
        void closeAccount();                //계좌 해지
        void checkMoney();                  //계좌 조회
    
        //추가 기능1
        void depositMoney();               // 계좌 입금
    
        //추가 기능2                            //계좌 출금
        void withdrawMoney();
};

#endif

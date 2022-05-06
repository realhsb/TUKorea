#include "Account.h"
#include "ATMachine.h"
#include "Statistics.h"
#include <iostream>
#include <random>
using namespace std;


ATMachine::ATMachine(int size, int balance, string password){
    this->pAcctArray = new Account[size];
    this->nMaxAccountNum = size;
    this->nMachineBalance = balance;
    this->strManagerPassword = password;
    this->currentAccountNum = 0;
}

ATMachine::~ATMachine(){
    if (pAcctArray) {
        delete [] pAcctArray;
    }
}

void ATMachine::displayMenu(){
    cout<<"----------------------\n-\tTUKOREA BANK\t-\n----------------------"<<endl;
    cout<<"1. 계좌 개설\n2. 계좌 조회\n3. 계좌 입금\n4. 계좌 출금\n5. 계좌 이체\n6. 계좌 해지\n7. 고객 관리\n9. 업무 종료\n";
}

bool ATMachine::isManager(string password){
    return this->strManagerPassword == password;
}

void ATMachine::displayReport(){
    cout << "----------------------\n" << endl;
    int sum = Statistics::sum(pAcctArray, nMaxAccountNum);
    int avg = Statistics::average(pAcctArray, nMaxAccountNum);
    int max = Statistics::max(pAcctArray, nMaxAccountNum);
    
    cout <<
    "ATM 현재 잔고 :\t" << nMachineBalance << "원\n" <<
    "고객 잔고 총액 :\t" << sum << "원 (총" << currentAccountNum << "명)\n" <<
    "고객 잔고 평균 :\t" << avg << "원\n" <<
    "고객 잔고 최고 :\t" << max << "원\n" << endl;
    cout << "----------------------\n-   고객 계좌 목록   -\n----------------------" << endl;
    int num = 1;
    Statistics::sort(pAcctArray, nMaxAccountNum);
    for(int i = 0;  i < nMaxAccountNum; i++){
        if(pAcctArray[i].getAcctID() == -1){
            continue;
        }else {
            cout << num++ << ".\t" << pAcctArray[i].getAccountName() << "\t" << pAcctArray[i].getAcctID() << "\t" << pAcctArray[i].getBalance() << "원" << endl;
        }
    }
}

//1. 계좌 개설
void ATMachine::createAccount(){
    random_device rng;
    uniform_int_distribution<int> dist(100, 1000);

    cout << "------ 개설 ------" << endl;
    int id = dist(rng);
    bool check = false;
    string name = "";
    string password = "";
    cout << "이름 입력 :\t";
    cin >> name;
    cout << "암호 입력 :\t";
    cin >> password;
    cout << endl;
    
    for(int i = 0; i < nMaxAccountNum; i++){
        if(pAcctArray[i].getAcctID() == id){
            id = dist(rng);
            i = 0;
        }
    }
    cout << "id : " << id << endl;
    for(int i = 0; i < nMaxAccountNum; i++){
        if(pAcctArray[i].getAcctID() == -1){
            pAcctArray[i].create(id, 0, name, password);
            check = true;
            currentAccountNum++;
            break;
        }else {
            continue;
        }
    }
    if(check){
        cout << name << "님 " << id << "번 계좌번호가 성공적으로 개설되었습니다. 감사합니다." << endl;
    }else {
        cout << "등록 가능한 계좌 수를 초과하여 등록에 실패하였습니다. 죄송합니다." << endl;
    }
}

//2.계좌 조회
void ATMachine::checkMoney(){
    cout << "------ 조회 ------" << endl;
    int id = 0;
    string password = "";
    int nBalance = 0;
    bool check = false;
    
    cout << "계좌번호 입력 :\t";
    cin >> id;
    cout << "비밀번호 입력 :\t";
    cin >> password;
    cout << endl;
    
    for(int i = 0; i < nMaxAccountNum; i++){
        if((nBalance = pAcctArray[i].check(id, password)) != AUTHENTIFICATION_FAIL){
            cout << "현재 잔액 : " << nBalance << endl;
            check = true;
            break;
        }
    }
    
    if(!check){
        cout << "계좌 인증에 실패하였습니다." << endl;
    }
}

// 3. 계좌 입금
void ATMachine::depositMoney(){
    cout << "------ 입금 ------" << endl;
    int id = 0;
    string password = "";
    int money = 0;
    int nBalance = 0;
    bool check = false;
    
    cout << "계좌번호 입력 :\t";
    cin >> id;
    cout << "비밀번호 입력 :\t";
    cin >> password;
    cout << "입금액  입력 :\t";
    cin >> money;
    while(money < 0){
        if(money < 0){
            cout << "1원 이상의 금액을 입력해야 합니다.\n입금액  입력 :\t";
        }
        cin >> money;
    }
    cout << endl;
    
    for(int i = 0; i < nMaxAccountNum; i++){
        if((nBalance = pAcctArray[i].deposit(id, password, money)) != AUTHENTIFICATION_FAIL){
            check = true;
            cout << "현재 잔액 : " << nBalance << endl;
            this->nMachineBalance += money;
            break;
        }
    }
    
    if(!check){
        cout << "계좌 인증에 실패하였습니다." << endl;
    }
}

// 4. 계좌 출금
void ATMachine::withdrawMoney(){
    cout << "------ 출금 ------" << endl;
    int id = 0;
    string password = "";
    int money = -1;
    int nBalance = 100;
    bool check = false;
    
    cout << "계좌번호 입력 :\t";
    cin >> id;
    cout << "비밀번호 입력 :\t";
    cin >> password;
    cout << "출금액  입력 :\t";
    cin >> money;
    while(money < 0 || this->nMachineBalance < money){
        if(money < 0){
            cout << "1원 이상의 금액을 입력해야 합니다.\n출금액  입력 :\t";
        }else if(this->nMachineBalance < money){
            cout << "ATM기기의 잔고가 부족합니다.\n출금액  입력 :\t";
        }
        cin >> money;
    }
    cout << endl;
    
    for(int i = 0; i < nMaxAccountNum; i++){
        if((nBalance = pAcctArray[i].withdraw(id, password, money)) != AUTHENTIFICATION_FAIL){
            if(nBalance >= 0){
                cout << "현재 잔액 : " << nBalance << "\n출금 완료\n" << endl;
            }else {
                cout << "잔액이 부족합니다." << endl;
            }
            check = true;
            break;
        }
    }
    
    if(!check){
        cout << "계좌 인증에 실패하였습니다." << endl;
    }
}

// 5. 계좌 이체
void ATMachine::transfer(){
    cout << "------ 이체 ------" << endl;
    int id_with = 0;   // 출금 계좌
    string password = "";
    int nBalance = -1;
    
    int id_depo = 0;   // 입금 계좌
    int money = 100;
    
    bool check = false;
    
    cout << "계좌번호 입력 :\t";
    cin >> id_with;
    cout << "비밀번호 입력 :\t";
    cin >> password;
    cout << "이체계좌 입력 :\t";
    cin >> id_depo;
    cout << "이체금액 입력 :\t";
    cin >> money;

    while(money < 0 || this->nMachineBalance < money){
        if(money < 0){
            cout << "1원 이상의 금액을 입력해야 합니다.\n출금액  입력 :\t";
        }else if(this->nMachineBalance < money){
            cout << "ATM기기의 잔고가 부족합니다.\n출금액  입력 :\t";
        }
        cin >> money;
    }
    cout << endl;
    
    for(int i = 0; i < nMaxAccountNum; i++){
        if((nBalance = pAcctArray[i].withdraw(id_with, password, money)) != AUTHENTIFICATION_FAIL){
            if(nBalance >= 0){
                cout << "현재 잔액 : " << nBalance << endl;
                check = true;
            }else {
                cout << "잔액이 부족합니다." << endl;
                return;
            }
        }
    }
    if(!check){
        cout << "계좌 인증에 실패하였습니다." << endl;
        return;
    }
    
    for(int i = 0; i < nMaxAccountNum; i++){
        if(pAcctArray[i].getAcctID() == id_depo){
            pAcctArray[i].deposit(id_depo, money);
            cout << "이체 완료" << endl;
            break;
        }
    }

}

// 6. 계좌 해지
void ATMachine::closeAccount(){
    cout << "------ 해지 ------" << endl;
    int id = 0;
    string password = "";
    bool check = false;

    int nBalance = 0;
    
    cout << "계좌번호 입력 :\t";
    cin >> id;
    cout << "비밀번호 입력 :\t";
    cin >> password;
    cout << endl;
    
    for(int i = 0; i < nMaxAccountNum; i++){
        
        if((nBalance = pAcctArray[i].check(id, password)) == 0){
            pAcctArray[i].close();
            cout << id << " 계좌가 해지되었습니다. 감사합니다." << endl;
            currentAccountNum--;
            //check = true;
            return;
        }else if(nBalance > 0){
            cout << id << "번 계좌를 해지할 수 없습니다. 잔액 : " << nBalance << endl;
            check = true;
            break;
        }
    }
    
    if(!check){
        cout << "계좌 인증에 실패하였습니다." << endl;
    }
}

// 7. 고객 관리
void ATMachine::managerMode(){
    cout << "------ 관리 ------" << endl;
    string password = "";
    cin >> password;
    if(isManager(password)){
        cout << "관리자입니다." << endl;
        displayReport();
    }else {
        cout << "비밀번호가 일치하지 않습니다." << endl;
        return;
    }
    
    
}


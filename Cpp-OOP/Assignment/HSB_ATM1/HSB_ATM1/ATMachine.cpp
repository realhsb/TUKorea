#include "ATMachine.h"
#include <iostream>
#include <random>
using namespace std;

random_device rng;
uniform_int_distribution<int> dist(100, 1000);

ATMachine::ATMachine(int size, int balance, string password){
    this->pAcctArray = new Account[size];
    this->nMaxAccountNum = size;
    this->nMachineBalance = balance;
    this->strManagerPassword = password;
}

ATMachine::~ATMachine(){
    
}

void ATMachine::displayMenu(){
    cout<<"----------------------\n-\tTUKOREA BANK\t-\n----------------------"<<endl;
    cout<<"1. 계좌 개설\n2. 계좌 조회\n3. 계좌 입금\n4. 계좌 출금\n6. 계좌 해지\n9. 업무 종료\n";
}

//1. 계좌 개설
void ATMachine::createAccount(){
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
            check = true;
            break;
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

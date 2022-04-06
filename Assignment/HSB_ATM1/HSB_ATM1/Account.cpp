#include "Account.h"
//#include <string>
#include <iostream>
using namespace::std;

Account::Account(){
    nID = -1;
    nBalance = 0;
    strAccountName = "";
    strPassword = "";
}

inline bool Account::authenticate(int id, string passwd){
    if(this->nID == id && this->strPassword == passwd){
        return 1;
    }else {
        return 0;
    }
}

void Account::create(int id, int money, string name, string password){
    this->nID = id;
    this->nBalance = money;
    this->strAccountName = name;
    this->strPassword = password;
}

void Account::close(){
    nID = -1;
    nBalance = 0;
    strAccountName = "";
    strPassword = "";
}

int Account::check(int id, string password){
    if(authenticate(id, password)){
        return nBalance;
    }else {
        return AUTHENTIFICATION_FAIL;
    }
}

int Account::deposit(int id, string password, int money){
    if(authenticate(id, password)){
        nBalance += money;
        return nBalance;
    }else {
        return AUTHENTIFICATION_FAIL;
    }
}

int Account::widraw(int id, string password, int money) {
    if(authenticate(id, password)){
        if(nBalance >= money){
            nBalance -= money;
        }else {
            return -2; //잔액 부족
        }
        return nBalance;
    }else {
        return AUTHENTIFICATION_FAIL;
    }
}

#include "Pay.h"

int CardPay::charge(int amount){
    return amount * (1 + this->interest);
}

int BankTransfer::charge(int amount){
    return amount * (1 + this->interest);
}

int MobilePay::charge(int amount){
    return amount * (1 + this->interest);
}

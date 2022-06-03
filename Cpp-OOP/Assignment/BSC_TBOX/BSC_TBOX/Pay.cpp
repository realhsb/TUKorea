#include "Pay.h"

int CardPay::charge(int amount){
    int charge = amount + amount * interest;
    return charge;
}

int BankTransfer::charge(int amount){
    int charge = amount + amount * interest;
    return charge;
}

int MobilePay::charge(int amount){
    int charge = amount + amount * interest;
    return charge;
}

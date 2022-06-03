#ifndef PAY_H
#define PAY_H
#define MOBILE_PHONE_PAYMENT 1
#define BANK_TRANSFER_PAYMENT 2
#define CREDIT_CARD_PAYMENT 3
#define MOBILE_PHONE_INTEREST_RATE 0.2 // 모바일 결제 수수료 비율(이자율)
#define BANK_TRANSFER_INTEREST_RATE 0.1 // 은행 이체 결제 수수료 비율 (이자율)
#define CREDIT_CARD_INTEREST_RATE 0.15 // 신용카드 결제 수수료 비율(이자율)

class Pay {
public:
    virtual int charge(int amount) = 0; // 결제하기
};

class CardPay : public Pay {
    double interest;
public:
    CardPay(double rate) { this->interest = rate; }
    int charge(int amount); // 결제금액 = 티켓 가격 + 티켓 가격 * 카드수수료 비율
};

class BankTransfer : public Pay {
    double interest;
public:
    BankTransfer(double rate) { this->interest = rate; }
    int charge(int amount); // 결제금액 = 티켓 가격 + 티켓 가격 * 은행수수료 비율
};

class MobilePay : public Pay {
    double interest;
public:
    MobilePay(double rate) { this->interest = rate; }
    int charge(int amount); // 결제금액 = 티켓 가격 + 티켓 가격 * 모바일수수료 비율
};

#endif

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

using std::string;


#define AUTHENTIFICATION_FAIL       -1
#define AUTHENTIFICATION_SUCCESS    1
#define BASE_ACCOUNT_ID             100

class Account {
    private :
        int nID;
        int nBalance;
        string strAccountName;
        string strPassword;

    private :
        inline bool authenticate(int id, string passwd);

    public :
        Account();
        void create(int id, int money, string name, string password);   // 계좌 개설
        void close();                                                                               // 계좌 해지
        int check(int id, string password);                                             // return 값 : nBalance (잔고) or 인증 실패(AUTHENTIFICATION_FAIL)
        int getAcctID() { return nID; }                                                    // 계좌 번호 읽어오기
    
        //추가 기능 1
        int deposit(int id, string password, int money);
    
        //추가 가능 2
        int widraw(int id, string password, int money);
};

#endif

#include <iostream>
#include <string>
using namespace std;

class Bomb {
    string title;
public :
    Bomb() {}
    Bomb(string title) {this->title = title;}
    string getTitle(){return title;}
};

class Weapon {
public :
    virtual ~Weapon();
    virtual void load (Bomb bomb) = 0;
    virtual void use() = 0;
};

class Tank : public Weapon {
    string title;
public :
    virtual ~Tank();
    virtual void load(Bomb bomb) {
        title = bomb.getTitle();
        cout << "탱크 " << bomb.getTitle ()<< " 을 적재함" << endl;
    }
    virtual void use() {
        cout << "탱크 " << title << " 을 적재함" << endl;
    }
};

class Fighter : public Weapon {
    string title;
public :
    virtual ~Fighter();
    virtual void load(Bomb bomb) {
        title = bomb.getTitle();
        cout << "전투기 " << bomb.getTitle ()<< " 을 적재함" << endl;
    }
    virtual void use() {
        cout << "전투기 " << title << " 을 적재함" << endl;
    }
};

class Missile : public Weapon {
string title;
public :
    virtual ~Missile();
    virtual void load(Bomb bomb) {
        title = bomb.getTitle();
        cout << "미사일 " << bomb.getTitle ()<< " 을 적재함" << endl;
    }
    virtual void use() {
        cout << "미사일 " << title << " 을 적재함" << endl;
    }
};

class Shop {
public :
    virtual Weapon* selectItem() = 0;
};

class BattleShop : public Shop {
public :
    virtual Weapon* selectItem() {
        int num = 0;
        cout << "----------\n무기 아이템 선택\n----------" << endl;
        cout << "1. 탱크\n2. 전투기\n3. 미사일\n" << endl;
        cout << "아이템 선택 (1~3) 그 외 종료 : ";
        cin >> num;
        cout << endl;
        switch(num) {
            case 1 : {
                // Tank tk, *pTk;
                // pTk = &tk;


                Tank* pTk;
                pTk = new Tank();
                return pTk;
            }
                
            case 2 : {
                Fighter *pFt;
                pFt = new Fighter();
                return pFt;
            }

            case 3 : {
                Missile *pMs;
                pMs = new Missile();
                return pMs;
            }
                
            default :
                cout << "종료합니다. " << endl;
                return NULL;
        }
    }    
};


int main(){
    BattleShop shop;
    Weapon* weapon;
    while(true){
        weapon = shop.selectItem();         // 반환 값을 통한 UpCasting
        if(weapon == NULL){
            return 0;
        }
        Bomb bomb("수소탄(hydrogen bomb)");
        weapon->load(bomb);
        weapon->use();
    }
    return 0;
}
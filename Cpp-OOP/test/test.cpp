#include <iostream>
#include <string>
using namespace std;

class Bomb {
    string title; //수소탄
public :
    Bomb() {}
    Bomb(string title) {this->title = title;}
    string getTitle(){return title;}
};



class Weapon {
 protected :
    string name;
public :
    virtual void load (Bomb bomb) = 0;
    virtual void use() = 0;
};

class Tank : public Weapon{
public :
    virtual void load(Bomb bomb) {
        name = bomb.getTitle();
        cout << "탱크 " << name << " 을 적재함." << endl;
    }
    virtual void use() {
        cout << "탱크 " << name << " 을 발사함." << endl;
    }
};

class Shop {
public : 
    virtual Weapon* selectItem() = 0;
};

class BattleShop : public Shop {
    virtual Weapon* selectItem(){
        int num = 0;
        cin << num;
        switch(num){
            case 1 : {
                
            }
        }
    }
};


int main(){
    BattleShop shop;
    Weapon* weapon;
    while(true){

        weapon = shop.selectItem();         // 반환 값을 통한 UpCasting
        Bomb bomb("수소탄(hydrogen bomb)");
    }
    return 0;
}
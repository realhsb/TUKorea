#include <iostream>
using namespace std;

class Power {
    int kick;
    int punch;
public :
    Power(int kick = 0, int punch = 0){
        this->kick = kick; this->punch = punch;
    }
    void show();

    //프렌즈 선언
    friend Power operator+(int op1, Power op2);
};
void Power::show(){
    cout << "kick = " << kick << ',' << "punch = " << punch << endl;
}

Power operator+(int op1, Power op2){
    Power tmp;
    tmp.kick = op1 + op2.kick;
    tmp.punch = op1 + op2.punch;
}
#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    
public :
int price, pages;
    Book(string title="", int price = 0, int pages = 0){
        this -> title = title; this -> price = price; this -> pages = pages;
    }
    void show(){
        cout << title << ' ' << price << "원" << pages << " 페이지" << endl;
    }
    string getTitle(){return title;}
    // Book& operator + (int price);
    // Book&  operator - (int price);
    friend void operator+(Book& b1, int price);
    friend void operator-(Book& b1, int price);
    
};

// Book& Book::operator+(int price){
//     this->price += price;
//     return *this;
// }
// Book& Book::operator-(int price){
//     this->price -= price;
//     return *this;
// }

void operator+ (Book& b1, int price){
    b1.price += price;

}
void operator- (Book& b1, int price){
    b1.price -= price;
}

// Book& operator- (Book& b1, int price){
//     b1.price -= price;
//     return b1;
// }

int main(){
    Book b1("청춘", 20000, 300), b2("미래", 30000, 500);
    b1.price += 200;
    b1.show();
}

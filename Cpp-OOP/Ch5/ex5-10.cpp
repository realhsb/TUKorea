//예제 5-10 얕은 복사 생성자를 사용하여 프로그램이 비정상 종료되는 경우

#include <iostream>
#include <cstring>
using namespace std;
class Person{                           //Person 클래스 선언
    char* name;
    int id;
    public :
        Person(int id, char* name);                 //생성자
        /* 컴파일러에 의해 디폴트 복사 생성자 삽입 (Person::Person(Person& p)*/
        Person::Person(Person& person);
        ~Person();                                          //소멸자
        void changeName(char* name);
        void show() {cout << id << ',' << name << endl;}
};

Person::Person(int id, char* name){     //생성자
    this->id = id;
    int len = strlen(name);                     //name의 문자 개수
    this->name = new char[len+1];       //name 문자열 공간 할당
    strcpy(this->name, name);               //name에 문자열 복사
}

Person::Person(Person& person){
    this->id = person.id;
    this->name = person.name;
}

Person::~Person(){          //소멸자, name 메모리 반환
    if(name)                        //만일 name에 동적 할당된 배열이 있으면
    delete [] name;             //동적 할당 메모리 소멸
}

void Person::changeName(char* name){
    if(strlen(name) > strlen(this->name)) return;
    strcpy(this->name, name);
}

int main(){
    Person father(1, "Kitae");      //(1) father 객체 생성
    Person daughter(father);     //(2) daughter 객체 생성

    cout << "daughter 객체 생성 직후 ____" << endl;
    father.show();                      //(3) father 객체 출력 
    daughter.show();                 //(3) daughter 객체 출력

    daughter.changeName("Grace");   //(4) daughter의 이름을 Grace로 변경
    cout << "daughter 이름을 Grace로 변경 후 ____" << endl;
    father.show();                      //(5) father 객체 출력
    daughter.show();                 //(5) daughter 객체 출력

    return 0;                               //(6), (7)  daughter, father 객체 소멸
                                                /*
                                                daughter, father 순으로 소멸,
                                                father가 소멸할 때, 프로그램 비정상 종료
                                                */
}
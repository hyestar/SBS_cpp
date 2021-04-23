#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cmath>

class Animal {//상속해주는 클래스의 멤버 변수, 함수를 외부에서도 활용할 수 있다.
public:
    int legs;
    char name[50];


    Animal(int legs, const char* name) {
       
        this->legs = legs;
        strcpy(this->name, name);
    }

    virtual void printInfo() { //속성이 따라가지 못할때는 virtual 가상함수를 사용하면 된다.
        printf("다리 %d, 이름 %s\n", legs, name);
    }
};

class Person : public Animal {  //protected로 바꾸면 protected하게 가져온다는것
public:
    char regist_no[30];

    Person(const char* regist_no) : Animal(2, "사람") {
        strcpy(this->regist_no, regist_no);
    }
    void printInfo() { //부모클래스가 virtual 함수일 경우 자식클래스는 virtual이 아니어도 된다. 대신 역성립은 안됨
        printf("이름 %s, 주민번호 %s\n", name, regist_no);
    }
};

int main() {
    Person* person = new Person("1234-5678");
    Animal* animal = person; //person 객체를 넣어줬으면 person안에 함수를 따라가야 하는데 animal 함수를 출력한다.
    //그럴때는 virtual 함수를 사용해서 확인과정을 거쳐야 한다. (먼저 속성찾아가고 virtual부터 한줄씩 확인하고 실행한다.)
    animal->printInfo();
    person->printInfo();
    return 0;
}
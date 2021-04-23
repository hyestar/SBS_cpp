#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cmath>

class Animal {//상속해주는 클래스의 멤버 변수, 함수를 외부에서도 활용할 수 있다.
public:
    int legs;
    char *name;


    Animal(int legs, const char* name) {
        this->name = new char[strlen(name) + 1];
        this->legs = legs;
        strcpy(this->name, name);
    }
    virtual ~Animal() {  // virtual 함수를 사용하는 이유는 원하는 값을 찾아가기 위함이다
        printf("애니멀 소멸자 호출됨\n");
        delete[] name;
    }
    virtual void printInfo() { //속성이 따라가지 못할때는 virtual 가상함수를 사용하면 된다.
        printf("다리 %d, 이름 %s\n", legs, name);
    }
};

class Person : public Animal {  //protected로 바꾸면 protected하게 가져온다는것
public:
    char* regist_no;

    Person(const char* regist_no) : Animal(2, "사람") {
        this->regist_no = new char[strlen(regist_no) + 1];
        strcpy(this->regist_no, regist_no);
    }
    virtual ~Person() {             //지속&연쇄적으로 부모의 소멸자를 호출, 소멸자는 부모클래스에 virtual 작성해두더라도 필요한 곳에 다 써줘야 한다.
        printf("person 소멸자 소출됨");
        delete[] regist_no;
    }
    void printInfo() { //부모클래스가 virtual 함수일 경우 자식클래스는 virtual이 아니어도 된다. 대신 역성립은 안됨
        printf("이름 %s, 주민번호 %s\n", name, regist_no);
    }
};

int main() {
    Animal* animal = new Person("1234-5678");  //animal타입을 만들어서 사람객체를 넣어줌
    delete animal; //person 소멸자는 사용해주지 않아서 메모리 누수 일어날 수 있음
    Person* person = new Person("9876-4567");
    delete person;  //부모의 소멸자까지 찾아가서 delete 해줌
    return 0;
}
//소멸자는 위로 올라가면서 검사하는 특성이 있기 때문에 부모클래스가 없다면 바로 자신만 delete하고 끝낸다.
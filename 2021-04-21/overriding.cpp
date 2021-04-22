#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

class Animal {
public:
	int legs;
	char name[20];

	Animal(int legs, const char* name) {
		this->legs = legs;
		strcpy(this->name, name);
	} 
	void printInfo() {
		printf("다리의 갯수 : %d\n", legs);
		printf("이름 : %s\n", name);
	}
};

class Person : public Animal {
public:
	char regist_no[40];

	Person(const char* regist_no) : Animal(2, "사람"){
		strcpy(this->regist_no, regist_no);
	}
	//함수 오버라이딩 => 재정의 해주는 것이다
	void printInfo() {
		printf("다리의 갯수 : %d\n", legs);
		printf("이름 : %s\n", name);
		printf("주민번호 : %s\n", regist_no);
	}
};
int main() {
	Person* p1 = new Person("1234-5678");
	Animal* a1 = new Animal(2, "닭");

	p1->printInfo();
	a1->printInfo();
	return 0;
}
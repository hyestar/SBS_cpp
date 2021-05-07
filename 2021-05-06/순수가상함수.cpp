//순수가상함수 : 몸체가 없는 가상함수, 무조건 상속 - 자식클래스에서 구현

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <ctime>

enum class Time
{
	Morning, Afternoon, Night
};

class Animal {
public:
	char name[50];
	Animal(const char* name) {
		strcpy(this->name, name);
	}

	virtual int getLegs() = 0; //상속해주는 애가 순수가상함수이기 때문에 몸체를 구성해줘야됨 필수임!!
	//만약 사용하게되면 상속받은 애들이 재정의하는 것이므로 굳이 좋다고 할 순 없다.

	void printInfo() {
		printf("이름 : %s, 다리 : %d\n", name, getLegs());
	}
};
class Person : public Animal {
private:
	Time time = Time::Morning;
public:
	Person(const char* name) :Animal(name) {}
	virtual int getLegs() {
		switch (time) {
		case Time::Morning:return 4;
		case Time::Afternoon:return 2;
		case Time::Night:return 3;
		}
		return 2;
	}
	void setTime(Time t) {
		this->time = t;
	}
};
class Dog : public Animal {
public:
	Dog() :Animal("개"){}
	virtual int getLegs() {
		return 4;
	}
};

int main() {
	// Animal* animal = new Animal("abcd");
	Person* person = new Person("길동");
	person->setTime(Time::Afternoon);
	person->printInfo();

	Dog* dog = new Dog;
	dog->printInfo();

	return 0;

}
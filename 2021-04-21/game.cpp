#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>

class character {
public:
	char name[50];
	int power;
	int attack;
	int range;
	int speed;


	character(int power, int attack, int range, int speed) {
		this->power = power;
		this->attack = attack;
		this->range = range;
		this->speed = speed;
	}

	void printfInfo() {
		printf("%s의 능력\n", name);
		printf("최대체력: %d\n", power);
		printf("최대공격: %d\n", attack);
		printf("공격거리: %d\n", range);
		printf("최대속도: %d\n", speed);

	}
};

class Goblin : public character {
public:
	Goblin() : character(10,5,10,10){
		strcpy(name, "고블린");
	}
};
class Orc : public character {
public:
	Orc() : character(15,7,12,8) {
		strcpy(name, "오크");

	}
};
class slaim : public character {
public:
	slaim() : character(20,3,11,9) {
		strcpy(name, "슬라임");
	}
};
class gol : public character {
public:
	gol() : character(12,9,9,5) {
		strcpy(name, "해골");
	}
};

int main() {
	character* units[10];

	srand(time(0)); //시드값 변경

	for (int i = 0; i < 10; i++) {
		switch (rand() % 4) {
		case 0:
			units[i] = new Orc();
			break;
		case 1:
			units[i] = new Goblin();
			break;
		case 2:
			units[i] = new gol();
			break;
		case 3:
			units[i] = new slaim();
			break;
		}
	}
	for (int i = 0; i < 10; i++) {
		units[i]->printfInfo();	
	}
	/*
	for (int i = 0; i < 10; i++) {
		delete units[i];	
	}
	=> delete 안해줘도 되는 이유는 main함수에 있기 때문에 어짜피 끝나면 힙도 다 날아가 버리기 때문에 상관 없어서
	*/
	return 0;
}

//연산자 오버로딩  +, -, *, /
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

class Vector {
public:
	float X;
	float Y;

	Vector(float X, float Y) {
		this->X = X;
		this->Y = Y;
	}
	Vector() {
		X = 0.0f;
		Y = 0.0f;
	}
	void printfInfo() {
		printf("%.2f, %.2f", X, Y);
	}
};


Vector operator+(Vector& v1, Vector& v2) {  //더하기 연산자는 v1.X + v2.X, v1.Y + v2.Y 이렇게 연산된다고 정의한 것이다.
	return Vector(v1.X + v2.X, v1.Y + v2.Y);
}

int main() {
	Vector v1 = Vector(100, 200);
	Vector v2 = Vector(1, 2);
	Vector v3 = v1 + v2;  // 일반 자료형이 아니기 때문에 +연산 불가능!! 따로 지정 해줘야 됨
	v3.printfInfo(); //정적으로 할당된 클래스 인스턴스에서 동작한다.
	return 0;
}
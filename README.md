# SBS_cpp
//오버로딩 : 동일한 이름을 갖고 있지만 다른 동작을 하게 만드는 것

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>

//연산자 오버로딩  +, -, *, /

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
};

Vector operator+(Vector& v1, Vector& v2) {  //더하기 연산자는 v1.X + v2.X, v1.Y + v2.Y 이렇게 연산된다고 정의한 것이다.
	return Vector(v1.X + v2.X, v1.Y + v2.Y);
}

int main() {
	Vector v1 = Vector(100, 200);
	Vector v2 = Vector(1, 2);
	Vector v3 = v1 + v2;  // 일반 자료형이 아니기 때문에 +연산 불가능!! 따로 지정 해줘야 됨

	return 0;
}


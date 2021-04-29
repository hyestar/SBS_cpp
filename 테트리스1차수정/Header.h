#define _CRT_SECURE_NO_WARNINGS
#include "TetrisHelper.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

//그리드를 만들어야됨. 화면 움직이는 부분 틀정도
#define GRID_WIDTH 7
#define GRID_HEIGHT 10
#define USERBLOCK_SIZE 3

int displayData [GRID_HEIGHT][GRID_WIDTH] = { 0, }; // 배열의 속성상 GRID_WIDTH부터 증가하기 때문에 HEIGTH(Y축)부터 써줘야한다. 그리고 초기화 해준 것이다

class Display {
public:
	void draw() {  //consol창에 시각적인 효과 부여
		for (int i = 0; i < GRID_HEIGHT; i++) {
			for (int k = 0; k < GRID_WIDTH; k++) {
				if (displayData[i][k] == 0) {
					drawPosition(k, i, false);
				}
				else {
					drawPosition(k, i, true);
				}
			}
		}
	}
};
/*
class Display {
public:
	void draw() {
		for (int i = 0; i < GRID_HEIGHT; i++) {
			for (int k = 0; k < GRID_WIDTH; k++) {
				drawPosition(k, i, displayData[i][k] == 1);
			}
		}
	}
};
위에 있는 소스코드와 동일 소드 줄인것
*/

class GameEngine {
public:
	//2차원배열이 두개 필요
	//유저블록 관리할 것과 기존 배열에 차있는 블록관리해야 함
	int gameGridData[GRID_HEIGHT][GRID_WIDTH] = { 
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0},
		{0,1,0,0,0,0,0},
		{0,1,0,0,1,0,0},
		{1,1,1,0,1,1,1},
		{1,1,1,1,1,1,0}
	};
	int userBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = {
		{1,1,1},
		{0,0,1},
		{0,0,1}
	};
	int blockX = 0; //유저블록의 위치 좌표를 찾기 위함
	int blockY = 0; 

	float elapsed = 0.0f;

	void init() {
		//최초에 게임엔진을 초기화 하는 과정
	}
	void next(float dt, char keyboardInput) {
		//키보드 입력값을 받아와서 어떤 일을 할지 결정(while 루프에서 매번 불려지는)
		//호출될때마다 유저블록이 떨어진다면 Y값이 변하게 될것이다.
		//blockY++; //너무 빨리 떨어지니깐
		elapsed = elapsed + dt;
		if (elapsed >= 0.5f) { //0.5보다 큰 경과시간
			if (canGoDown()) {
				blockY++;
			}
			else {
				//더 내려갈수 없으면 userBlock을 gameGridData에 전사
				trans();
			}
	
			elapsed = elapsed - 0.5f;
		}
	}

	//블록이 아래로 내려갈 수 있냐
	bool canGoDown() {
		for (int i = 0; i < USERBLOCK_SIZE; i++) {
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				if (userBlock[i][k] == 1 && i + blockY + 1 >= GRID_HEIGHT) // blockY는 좌표!! 그리드 밖을 벗어나면 안됨
					return false;

				if (userBlock[i][k] == 1 && gameGridData[i + blockY + 1][k + blockX] == 1) // 블록이 아래 채워져있는데 내려가면 안됨
					return false;

			}
		}
		return true;
	}


	//블록이 왼쪽으로 갈 수 있냐
	bool canGoLeft() {
		return true;
	}
	//블록이 오른쪽으로 갈 수 있냐
	bool canGoRight() {
		return true;
	}

	void trans() {
		for (int i = 0; i < USERBLOCK_SIZE; i++) {
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				gameGridData[i + blockY][k + blockX] = userBlock[i][k] == 1 ? userBlock[i][k] : gameGridData[i + blockY][k + blockX];
			}
		}
		// 한줄이 가득 차 있는지 확인
		// 새로운블록 생성
		makeUserBlock();
	}

	void makeUserBlock() {
		blockX = 0;
		blockY = 0;

		// todo : 랜덤을 통해서 블록을 만든다
	}

	void makeDisplayData() { //전사하는 과정
		for (int i = 0; i < GRID_HEIGHT; i++) {
			for (int k = 0; k < GRID_WIDTH; k++) {
				displayData[i][k] = gameGridData[i][k]; //유저블록데이터 빼고 넘겨준것임
			}
		}
		for (int i = 0; i < USERBLOCK_SIZE; i++) {
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				if (i + blockY<0 || i + blockY>GRID_HEIGHT) { //유저블록이 Y축보다 위에 있거나 아래있어서 그리드밖에 있는 경우
					// DO NOTHING
				}
				else if (k + blockX<0 || k + blockX>GRID_WIDTH) {  //유저블록이 X축보다 위에 있거나 아래있어서 그리드 밖에 있는 경우
					// DO NOTHING
				}
				else {
					//displayData[i + blockY][k + blockX] = userBlock[i][k]==1?userBlock[i][k]:displayData[i+blockY][k+blockX]; // X, Y축으로 둘다 넘어가지 않았다면 안에 있을 것이므로 userBlock의 위치 넘김
					int _x = k + blockX;
					int _y = i + blockY;
					displayData[_y][_x] = userBlock[i][k] | displayData[_y][_x];  //비트연산자가 속도가 더 빠름
				
				}
			}
		}
	}

};

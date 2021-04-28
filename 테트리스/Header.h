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
	int gameGridData[GRID_HEIGHT][GRID_WIDTH] = { 0, };
	int userBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = {
		{1,1,1},
		{0,0,1},
		{0,0,1}
	};
	int blockX = 0; //유저블록의 위치 좌표를 찾기 위함
	int blockY = 0; 

	void init() {
		//최초에 게임엔진을 초기화 하는 과정
	}
	void next(float dt, char keyboardInput) {
		//키보드 입력값을 받아와서 어떤 일을 할지 결정(while 루프에서 매번 불려지는)
		//호출될때마다 유저블록이 떨어진다면 Y값이 변하게 될것이다.
		blockY++;
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
					displayData[i + blockY][k + blockX] = userBlock[i][k]; // X, Y축으로 둘다 넘어가지 않았다면 안에 있을 것이므로 userBlock의 위치 넘김
				}
			}
		}
	}

};

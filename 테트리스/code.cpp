#include "Header.h"
#define INTERVAL 1.0/60.0
//clock 타임 : 프로그램이 시작된 시간 ctime이 선언된 순간 실행된다.
int main() {
	
	float prev = (float)clock() / CLOCKS_PER_SEC; // 프로그램이 시작된 순간부터 몇초가 지났는지 알 수 있다
	Display* display = new Display();
	GameEngine* gameEngine = new GameEngine();

	showConsoleCursor(false);
	
	while (true) { //1초에 60번 움직이는 while루프를 만든것이다. 갱신시켜주는것
		float curr = (float)clock() / CLOCKS_PER_SEC;
		float dt = curr - prev;  //현재시간과 전에 시간을 빼서 델타타임을 지정해주는 것이다.

		if (dt > INTERVAL) continue; //정해주는 1/60보다 작다면 처음으로 돌아가게
		prev = curr;
		// printf("%.3f\n", curr);

		bool left = keyState('a');  //window 환경에서 키보드가 눌려져있는지 안눌렸는지 안눌려져있으면 그냥 떨어져야 하니깐
		if (left) {
			//왼쪽으로 이동

		}
		else {
			//그냥 블록 떨어지게
		}

		gameEngine->next(dt, 0); //다음연산을 할때는 dt을 넣어줘야 한다
		//화면출력
		gameEngine->makeDisplayData();
		display->draw();  //위에서 display 객체 만들고 draw함수 실행

		//게임상태 판별(게임이 이겼는지 졌는지 게임종료인지 등등 판별 확인해서 루프안을 탈출할지 말지 결정하는 과정)
		bool right = keyState('d');
	}

	return 0;
}
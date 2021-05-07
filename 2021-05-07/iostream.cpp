#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;



int main() {

	std::string str1 = "apple";
	std::string str2 = "banana";
	/* 솔루션 1
	if (str1.compare(str2) == 0) {
		printf("두 문자열은 같다");
	}
	else printf("두 문자열은 다르다");
	*/

	/* 솔루션 2 */
	if (strcmp(str1.c_str(), str2.c_str()) == 0) {
		printf("두 문자열은 같다");
	}
	else printf("두 문자열은 다르다");
	


	/*
	std::string myStr = "Hello World!"; //정적인 형태의 클래스 인스턴스로 선언 & 사용
	myStr = myStr + " Hello C++";
    //std::string* myStrPointer; //동적할당 => 따라서 사용자가 메모리 관리를 해줘야 한다.
	//동적할당에서는 연산자 오버로딩 안됨 왜냐? 주소에 더하거나 문자열을 넣는다는것은 X
	//그래서 정적인 클래스로 만들어주는 것이다.

	//myStr은 클래스다 -> 클래스는 int 형태로 강제 형변환 된다
	//강제 형변환 된 숫자는 주소값으로 인식된다


	printf("%s\n", myStr.c_str()); //정적이기 때문에 . 꼭 필요하다

	std::cout << myStr;
	cout << "hi";
	*/

	/*
	char mystring[100];
	printf("Hello\n");
	strcpy(mystring, "Hello World!");
	strcat(mystring, " Hello C++"); // strcat는 글자를 strcpy된 것 뒤에 붙여주는 것이다.
	
	printf("%s",mystring);
	*/
	return 0;
}
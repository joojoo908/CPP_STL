// ------------------------------------------------------------
//  - 3 / 25 -
// ------------------------------------------------------------
// 동적(real-time(돌려봐야 알 수 있는)) 할당과 스마트 포인터 -
// RAII -자원의 생명주기를 객체의 생명주기와 일치시키는 프로그래밍 기법
// ------------------------------------------------------------



#include <iostream>
#include <vector>
#include <numeric>
#include <memory>
#include <fstream>
#include <string>

#include "save.h"
using namespace std;


class Dog {
public:
	Dog() { cout << "멍멍" << endl; }
	~Dog() { cout << "dead" << endl; }
};

class 스마트 {
	Dog* p;
public:
	스마트() {}
	스마트(Dog* p) : p{ p } {}   // RAII 자원의 생명 주기를 객체의 생성 주기와 일치시킨다
	~스마트() {
		delete p;
		cout << "예외가 발생하더라도 지역객체는 반드시 소멸됨을 보장한다 (stack unwinding)" << endl;
		//스택 언와인딩 - 스택을 되집어 가면서 만들어진 데이터를 소멸시킨다
	}
};

void f() 
{
	//핸들러가 존재할때만 사용한다 (자바와 같은 경우엔 쓰레기차 운영)
	unique_ptr<Dog[]> p = make_unique<Dog[]>(3);  // 표준 스마트 포인터 = 동적할당 -> 여러개 생성
	
	//예외발생
	//throw 123;

	cout << "이 문장은 출력되지 않는다" << endl;

}



//--------
int main()
//--------
{
	//문제 "main.cpp" 에 있는 소문자를 모두 대문자로 바꾸어 "메인 대문자.cpp"에 저장하라
	ifstream in{"main.cpp"};
	if (not in) {
		return 1;
	}
	ofstream out{ "메인 대문자.cpp" };

	char c{};
	in >> noskipws;
	while (in>>c) {
		if (islower(c))
			c =toupper(c);
		out << c;
	}

	save("main.cpp");
	
	
}